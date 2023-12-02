#include <bits/stdc++.h>

using namespace std;

/*
TC: O(N+M)
SC: O(N)

we can calculate the distance from the starting node to all other nodes using breadth-first search.
Breadth-first search goes through the nodes one level after another.
*/

void bfs(int src, vector<int> adj[], vector<bool>& vis){

    int n = vis.size();
    vis[src] = 1;
    int dist[n] = {0};

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(auto u: adj[top]){
            if(!vis[u]){
                vis[u] = 1;
                q.push(u);
                dist[u] = dist[top]+1;
            }
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
            bfs(i,adj,vis);
        }
    }


}