#include <bits/stdc++.h>

// time complexity : O(V+E)
// Space complexity: O(V)
using namespace std;

void dfs(int v, vector<int> adj[], vector<bool>& vis){
    vis[v] = 1;

    for(auto u: adj[v]){
        if(!vis[u]){
            dfs(u,adj,vis);
        }
    }
}

int main(){

    int n = 6;
    vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

    vector<int> adj[n];

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> vis;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i,adj,vis);
        }
    }


}