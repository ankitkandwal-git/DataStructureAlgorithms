#include<bits/stdc++.h>
using namespace std;

bool solve(int i,int n,int k,int total,vector<int>&arr,vector<vector<int>>&dp){
    if(i==0) return true;
    if(i==0){
        if(arr[i]==total) return true;
        else return false;
    }
    if(dp[i][total]!=-1) return dp[i][total];
    bool notPick = solve(i-1,n,k,total,arr,dp);
    bool pick = false;
    if(arr[i]<=total){
        pick = solve(i-1,n,k,total-arr[i],arr,dp);
    }
    else pick = false;
    return dp[i][total] = pick || notPick;
}
bool subsetSum(int n ,int k,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(n-1,n,k,k,arr,dp);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(subsetSum(n,k,arr)) cout<<"YES\n";
    else cout<<"NO\n";
}