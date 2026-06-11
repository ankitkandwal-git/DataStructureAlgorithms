#include<bits/stdc++.h>
using namespace std;

/// @brief 
/// @param n 
/// @param e 
/// @param edges 
/// @return 
void dfs(int node,vector<int>&visited,vector<vector<pair<int,int>>>&adj,stack<int>&s){
    visited[node]=1;
    for(auto it:adj[node]){
        int neighbour = it.first;
        if(!visited[neighbour]){
            dfs(neighbour,visited,adj,s);
        }
    }
    s.push(node);
}

vector<int>shortestPath(int n,int e,vector<vector<int>>&edges){
    vector<int>visited(n,0);
    vector<vector<pair<int,int>>>adj(n);
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
    }
    stack<int>s;
    dfs(0,visited,adj,s);
    vector<int>dist(n,INT_MAX);
    dist[0]=0;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(dist[node] != INT_MAX){
            for(auto it:adj[node]){
                int neighbour = it.first;
                int weight = it.second;
                if(dist[node]+weight < dist[neighbour]){
                    dist[neighbour] = dist[node]+weight;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i] == INT_MAX){
            dist[i]=-1;
        }
    }
    return dist;
}
int main(){
    int n,e;
    cout<<"Enter the number of nodes and edges: ";
    cout<<"Enter the edges in the format: source destination weight"<<endl;
    cin>>n>>e;
    vector<vector<int>>edges(e,vector<int>(3));
    for(int i=0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    vector<int>ans = shortestPath(n,e,edges);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}