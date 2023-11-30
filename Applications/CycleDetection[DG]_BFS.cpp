
#include <bits/stdc++.h>

// TC: O(V+E)
// Using Kahn's Algorithm
using namespace std;

bool cycleDetect(int n, vector<int> adj[]){
    
    vector<int> indegree(n,0);
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++)
                 indegree[adj[i][j]]++;
    }
    
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        
        for(auto u: adj[top]){
        
            indegree[u]--;
            if(indegree[u] == 0){
                q.push(u);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(indegree[i]) return false;
    }
    
    return true;
    
}
int main() {
    // Write C++ code here
    int n = 6;
    vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

    vector<int> adj[n];
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            if(cycleDetect(n,adj)); // cycle detected
        }
    }
    // no cycle detected
    return 0;
}
