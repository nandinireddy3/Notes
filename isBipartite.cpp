// TC: O(V+E)
// DFS
bool isBipartite(int src, vector<int> adj[], vector<int> &vis){
    
    for(auto u: adj[src]){
        if(!vis[u]){
            vis[u] = -vis[src];
            if(!isBipartite(u,adj,vis)) return false;
        }
        else if(vis[u] == vis[src]) return false;
    }
    
    return true;
}

// BFS
bool isBipartite(int src, vector<int> adj[], vector<int> &vis){
    
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    
    while(!q.empty()){
        int top = q.front(); q.pop();
        
        for(auto u:adj[top]){
            if(!vis[u]){
                vis[u] = -vis[top];
                q.push(u);
            }
            else if(vis[u] == vis[top]) return false;
        }
    }
    return true;
}
