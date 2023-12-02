/*
Minimum Spanning Tree -
V vertices, V-1 edges
Connected and Acyclic same as a tree
with minimum weight.

GREEDY APPROACH
1. select a minimum weighted edge.
2. Dont include if it forms a cycle.

For Undirected graph

TC: O(V+E)+O(ElogV)
SC: O(N)+O(N)+O(E)
*/

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

    int find(int a){ // O(logn)

        if(a == parent[a]) return a;
        
        return parent[a] = find(parent[a]); // path compression // O(alpha)
    }

    bool same(int a, int b){
        return (find(a) == find(b));
    }

    void unite(int a, int b){ // O(1)
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

int kruskals(int n, vector<vector<int>> adj[]){ // adj[1] = [[],[]]

    int mstWt = 0;
    vector<pair<int,pair<int,int>>> edges;

    for(int i = 0 ; i < n; i++){
        for(auto it:adj[i])
        edges.push_back({it[1],{i,it[0]}});
    }

    sort(edges.begin(),edges.end());

    DSU ds(n);

    for(int i = 0; i < edges.size(); i++){
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(!ds.same(a,b)) {
            ds.unite(a,b);
            mstWt += w;
        }
    }

    return mstWt;

}

int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    
    int mstWt = kruskals(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}