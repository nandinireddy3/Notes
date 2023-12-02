#include <bits/stdc++.h>

using namespace std;

class DSU{

public:
    int* parent;
    int* size;
    DSU(int n){

        parent = new int(n);
        size = new int(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int a){

        if(a == parent[a]) return a;
        
        return parent[a] = find(parent[a]); // path compression
    }

    bool same(int a, int b){
        return (find(a) == find(b));
    }

    void unite(int a, int b){
        int parenta = find(a);
        int parentb = find(b);

        if(parenta == parentb) return;

        if(size[parenta] < size[parentb]){
            parent[parenta] = parentb;
            size[parentb] += size[parenta];
        }
        else{
            parent[parentb] = parenta;
            size[parenta] += size[parentb];
        }
    }
};