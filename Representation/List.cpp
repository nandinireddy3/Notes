#include <bits/stdc++.h>

using namespace std;

int main(){

    int n = 6;
    vector<vector<int>> edges={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

    vector<int> adj[n];

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    for(int i = 0; i < n; i++){
        for(auto u: adj[i]){
            cout << u << endl;
        }
    }
}