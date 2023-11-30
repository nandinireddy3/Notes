#include <bits/stdc++.h>

using namespace std;

/*
DYNAMIC PROGRAMMING APPROACH
RELAX[dist[u]+w < dist[v]] for n-1 times

TC: O(V*E)
SC: O(V)
FAILS WHEN GRAPH CONTAINS NEGATIVE CYCLES
DETECTS GRAPHS CONTATING NEGATIVE CYCLES.
*/

void BellmanFord(int n, vector<vector<int>>& edges, int src){

    vector<int> dist(n+1,1000);
    dist[src] = 0;
    cout << src << endl;
    for(int i = 0; i < n-1; i++){
        for(auto &e:edges){
            if(dist[e[0]]+e[2] < dist[e[1]]){
                dist[e[1]] = dist[e[0]]+e[2];
            }
        }
    }

    
    for(int i = 1; i < n+1; i++){
        cout << "index: " << i << " dist: "<< dist[i] << endl;
    }
    
}

int main(){

    int n=7;
	vector<vector<int>> edges={{1,2,6},{1,3,5},{1,4,5},{3,2,-2},{4,3,-2},{2,5,-1},{3,5,1},{4,6,-1},{5,7,3},{6,7,3}};

    BellmanFord(n,edges,1);

}
