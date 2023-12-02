#include <bits/stdc++.h>

/*
Directed Acyclic graph
TC: O(V+E)
SC: O(V)
*/
using namespace std;

void dfs(int v, vector<int>& vis, vector<int> adj[], stack<int>& s){

    vis[v] = 1;
    for(auto it:adj[v]){
        if(!vis[it]){
            dfs(it,vis,adj,s);
        }
    }
    s.push(v);
}