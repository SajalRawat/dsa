#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* r, int x) {
    if (!r) return new Node(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}

bool search(Node* r, int x) {
    if (!r) return false;
    if (r->data == x) return true;
    return x < r->data ? search(r->left, x) : search(r->right, x);
}

Node* minNode(Node* r) {
    while (r->left) r = r->left;
    return r;
}

Node* removeNode(Node* r, int x) {
    if (!r) return r;

    if (x < r->data)
        r->left = removeNode(r->left, x);
    else if (x > r->data)
        r->right = removeNode(r->right, x);
    else {
        if (!r->left) {
            Node* t = r->right;
            delete r;
            return t;
        }

        if (!r->right) {
            Node* t = r->left;
            delete r;
            return t;
        }

        Node* t = minNode(r->right);
        r->data = t->data;
        r->right = removeNode(r->right, t->data);
    }

    return r;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << ' ';
    inorder(r->right);
}

int depth(Node* r) {
    if (!r) return 0;
    return 1 + max(depth(r->left), depth(r->right));
}

Node* copyTree(Node* r, bool mirror = false) {
    if (!r) return nullptr;

    Node* n = new Node(r->data);

    n->left = copyTree(mirror ? r->right : r->left, mirror);
    n->right = copyTree(mirror ? r->left : r->right, mirror);

    return n;
}

void parents(Node* r) {
    if (!r) return;

    if (r->left || r->right) {
        cout << r->data << ": ";

        if (r->left) cout << "L=" << r->left->data << ' ';
        if (r->right) cout << "R=" << r->right->data;

        cout << '\n';
    }

    parents(r->left);
    parents(r->right);
}

void leaves(Node* r) {
    if (!r) return;

    if (!r->left && !r->right)
        cout << r->data << ' ';

    leaves(r->left);
    leaves(r->right);
}

void levelOrder(Node* r) {
    if (!r) return;

    queue<Node*> q;
    q.push(r);

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        cout << n->data << ' ';

        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
    }
}

void freeTree(Node* r) {
    if (!r) return;

    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    Node* r = nullptr;

    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : a)
        r = insert(r, x);

    cout << "Inorder: ";
    inorder(r);

    cout << "\nFound 40: " << search(r, 40);

    cout << "\nDepth: " << depth(r);

    cout << "\nParents and children:\n";
    parents(r);

    cout << "Leaves: ";
    leaves(r);

    cout << "\nLevel order: ";
    levelOrder(r);

    Node* m = copyTree(r, true);

    cout << "\nMirror inorder: ";
    inorder(m);

    r = removeNode(r, 30);

    cout << "\nAfter deleting 30: ";
    inorder(r);

    cout << '\n';

    freeTree(m);
    freeTree(r);
}