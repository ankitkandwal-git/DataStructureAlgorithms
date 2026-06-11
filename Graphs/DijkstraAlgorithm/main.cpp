#include<bits/stdc++.h>
using namespace std;

vector<int>dijkstra(int n,vector<pair<int,int>>adj[],int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n,INT_MAX);
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int d = x.first;
        int node = x.second;
        if(d>dist[node]) continue;
        for(auto k:adj[node]){
            int adjNode = k.first;
            int wt = k.second;
            if(dist[node]+wt<dist[adjNode]){
                dist[adjNode]=dist[node]+wt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;
    vector<pair<int,int>>adj[n];
    cout<<"Enter the edges (u v w): "<<endl;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // For undirected graph
    }
    int start;
    cout<<"Enter the starting vertex: ";
    cin>>start;
    vector<int>dist = dijkstra(n,adj,start);
    cout<<"Shortest distances from vertex "<<start<<":"<<endl;
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            cout<<"Vertex "<<i<<": Unreachable"<<endl;
        }else{
            cout<<"Vertex "<<i<<": "<<dist[i]<<endl;
        }
    }
    return 0;

}