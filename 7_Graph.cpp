#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int findRoot(vector<int>& p, int x) {
    if (p[x] == x) return x;
    return p[x] = findRoot(p, p[x]);
}

bool unite(vector<int>& p, int a, int b) {
    a = findRoot(p, a);
    b = findRoot(p, b);

    if (a == b) return false;

    p[a] = b;
    return true;
}

void prim(vector<vector<int>>& g, int n) {
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> used(n, false);

    key[0] = 0;
    int total = 0;

    for (int c = 0; c < n; c++) {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || key[i] < key[u]))
                u = i;

        used[u] = true;

        if (parent[u] != -1) {
            cout << parent[u] << '-' << u
                 << " (" << key[u] << ")\n";

            total += key[u];
        }

        for (int v = 0; v < n; v++) {
            if (g[u][v] > 0 && !used[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim total: " << total << '\n';
}

void kruskal(vector<vector<int>>& g, int n) {
    vector<Edge> e;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (g[i][j] > 0)
                e.push_back({i, j, g[i][j]});

    sort(e.begin(), e.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    vector<int> p(n);

    for (int i = 0; i < n; i++)
        p[i] = i;

    int total = 0, count = 0;

    for (Edge x : e) {
        if (unite(p, x.u, x.v)) {
            cout << x.u << '-' << x.v
                 << " (" << x.w << ")\n";

            total += x.w;

            if (++count == n - 1)
                break;
        }
    }

    cout << "Kruskal total: " << total << '\n';
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    prim(g, n);
    kruskal(g, n);
}