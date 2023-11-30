// we start from a node, and start doing BFS level-wise, 
// if somewhere down the line, we visit a single node twice, 
// it means we came via two paths to end up at the same node.
#include <bits/stdc++.h>
// TC: O(N + 2E) + O(N)
using namespace std;

bool cycleDetect(int node, vector<int> adj[], vector<bool>& vis){
    
    queue<pair<int,int>> q;
    
    q.push({node,-1}); // {node,parent}
    vis[node] = true;
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        int cur = top.first;
        int parent = top.second;
        
        for(auto u: adj[cur]){
            if(!vis[u]){
                vis[u] = true;
                q.push({u,cur});
            }
            if(u != parent) return true;
            
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
