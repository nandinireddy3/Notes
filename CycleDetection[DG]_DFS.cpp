
#include <bits/stdc++.h>

using namespace std;
// if node that is on the same path is visited again 
bool cycleDetect(int node, vector<int> adj[], vector<bool>& vis, vector<int>& path){
    
    vis[node] = true;
    path[node] = 1;
    for(auto u:adj[node]){
        if(!vis[u]){
            if(cycleDetect(u,adj,vis)) return true;
        }
        else if(path[u]){
            return true;
        }
    }
    
   path[node] = 0;
    return false;
    
}
int main() {
    // Write C++ code here
    int n = 6;
    vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

    vector<int> adj[n];

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> vis[n];
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            if(cycleDetect(i,-1,adj,vis)) // cycle detected
        }
    }
    // no cycle detected
    return 0;
}
