/*
Kahn's algorithm:[DAG]
    1- Take the element with indegree = 0
    2- Push it to the queue
    3- Decrease the indegrees of adj nodes by 1
    4- push adj node if indegree = 0
    5- used to detect the cycle
    TC- O(V+E)
    SC: O(2V)
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
  {
      // code here
      vector<int> topo;
      
      queue<int> q; // all the elements in queue are with indegree = 0;
      
      vector<int> indegree(V,0); // the number of entering edges to a node;
      
      for(int i = 0; i < V; i++){
          for(auto it:adj[i]){
              indegree[it]++;
          }
      }
      
      for(int i = 0; i < V; i++){
          if(indegree[i] == 0){
              q.push(i);
          }
      }
      
      while(!q.empty()){
          int node = q.front();
          q.pop();
          topo.push_back(node);
          
          for(auto it:adj[node]){
              indegree[it]--;
              
              if(indegree[it] == 0) q.push(it);
          }
      }
      
      return topo;
  }