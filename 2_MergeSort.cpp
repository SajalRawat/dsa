// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>

void merge(int a[], int l, int m, int r){
    int i= l;
    int j= m+1;
    int k=0;
    int temp[100];
    while(i<=m && j<=r){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{//if(a[i]>a[j]){
            temp[k++]=a[j++];
        }
    }
    while(i<=m){
        temp[k++]=a[i++];
    }
    while(j<=r){
        temp[k++]=a[j++];
    }
    for(int i=l,k=0; i<=r; i++,k++){
        a[i]=temp[k];
    }
}


void mergesort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,  l,  m);
        mergesort(a, m+1, r);
        merge(a, l , m, r);
    }
}

    


int main() {
    // Write C++ code here
    int a[]= {22,43,65,66,1,23};
    
    mergesort(a, 0, 5);
    for(int ele: a) std::cout << ele <<"  ";
    return 0;
}