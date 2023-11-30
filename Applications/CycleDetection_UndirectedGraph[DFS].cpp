// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

// TC: O(N+2E)
// SC: O(N)

using namespace std;

bool cycleDetect(int node, int parent, vector<int> adj[], vector<bool>& vis){
    
    vis[node] = true;
    for(auto u: adj[node]){
        if(!vis[u]){
            if(cycleDetect(u,v,adj,vis)) return true;
        }
        else if(u != parent){
            return true;
        }
    }
    
    return false;
}
int main() {
    // Write C++ code here
    int n = 6;
    vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

    vector<int> adj[n];

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
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
