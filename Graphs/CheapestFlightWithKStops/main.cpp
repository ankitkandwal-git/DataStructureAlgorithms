#include<bits/stdc++.h>
using namespace std;

int cheapestFlightWithKLimit(int n,vector<vector<int>>&flights,int start,int end,int k){
    vector<vector<pair<int,int>>>adj(n);
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{start,0}});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int cost=it.second.second;
        if(node==end) return cost;
        if(stops>k) continue;
        for(auto it:adj[node]){
            q.push({stops+1,{it.first,cost+it.second}});
        }
    }
    return -1;
}

int main(){
  int m;
  cout<<"Enter the number of flights: ";
  cin>>m;
  vector<vector<int>>flights(m,vector<int>(3));
  cout<<"Enter the flight details (source destination cost): "<<endl;
  for(int i=0;i<m;i++){
      cin>>flights[i][0]>>flights[i][1]>>flights
[i][2];  }
  int start,end,k;
  cout<<"Enter the source, destination and maximum stops: ";
  cin>>start>>end>>k;
  int result=cheapestFlightWithKLimit(m,flights,start,end,k);
  if(result!=-1){
      cout<<"The cheapest flight cost is: "<<result<<endl;
  } else {
      cout<<"No such flight exists within the given stops."<<endl;
  }
  return 0;
}