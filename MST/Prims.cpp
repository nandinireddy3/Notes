/*
Notes:
	1- No self loop or parelled edges 
	2- We try to connect all the nodes 
	3- We start by picking 1 node 
	4- Then we select the smallest edge from this node 
GREEDY:
    1- Take Minimum weighted edge node
    2- Take the next minimum weighted edge nodes that is connected to 
    the current tree
TC- ElogE
SC- O(E+V)
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int Prims(int n, vector<vector<int>> adj[]){

    vector<bool> vis(n,false);
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    int sum = 0;
    pq.push({0,0});

    while(!pq.empty()){

        auto top = pq.top();
        pq.pop();
        int wt = top.first;
        int node = top.second;

        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;
        for(auto it:adj[node]){

                int adjNode = it[0];
                if(!vis[adjNode]){
                    pq.push({it[1],it[0]});
                }   
        }
    }

    return sum;
}

