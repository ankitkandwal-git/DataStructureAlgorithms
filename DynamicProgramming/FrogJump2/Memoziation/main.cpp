#include<bits/stdc++.h>
using namespace std;

int frogJump(int n ,vector<int>&height,vector<int>&dp, int k){
    if(n==0) return 0;
    if(dp[n] != -1) return dp[n];
    int min_energy = INT_MAX;
    for(int i=1;i<=k;i++){
        if((k-i) >= 0){
            int jump = frogJump(n-i,height,dp,k) + abs(height[n] - height[n-i]);
            min_energy = min(min_energy,jump);
        }
    }
    return dp[n] = min_energy;
}
int main(){
    int n;
    cout<<"Enter number of stairs: ";
    cin>>n;
    int k;
    cout<<"Enter maximum jump length: ";
    cin>>k;
    vector<int>height(n);
    for(int i=0;i<n;i++){
        cout<<"Enter height of stair ";
        cin>>height[i];
    }
    vector<int>dp(n+1,-1);
    cout<<"Minimum energy required to reach the top: "<<frogJump(n-1,height,dp,k)<<endl;
    return 0;
}