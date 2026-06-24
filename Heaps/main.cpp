#include<bits/stdc++.h>
using namespace std;

class MinimumCostToJoinRods{
    public:
    int minCost(vector<int>&rods){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i:rods){
            pq.push(i);
        }
        int totalCost = 0;
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }
        return totalCost;
    }
};

int main(){
    MinimumCostToJoinRods obj;
    int n;
    cout<<"Enter the number of rods: ";
    cin>>n;
    vector<int>rods(n);
    cout<<"Enter the lengths of the rods: ";
    for(int i=0;i<n;i++){
        cin>>rods[i];
    }
    int result = obj.minCost(rods);
    cout<<"The minimum cost to join the rods is: "<<result<<endl;
    return 0;
}