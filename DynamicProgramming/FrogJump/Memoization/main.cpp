#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int>&height, vector<int>&dp){
    if(n==0) return 0;
    if(n==1) return abs(height[1]-height[0]);
    if(dp[n] != -1) return dp[n];
    int firstJump = abs(height[n]-height[n-1]+frogJump(n-1,height,dp));
    int secondJump = abs(height[n]-height[n-2]+frogJump(n-2,height,dp));
    return dp[n] = min(firstJump,secondJump);
}
int main(){
    int n;
    cout<<"Enter number of stairs: ";
    cin>>n;
    vector<int>height(n);
    cout<<"Enter heights of stairs: ";
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    vector<int>dp(n,-1);
    cout<<"Minimum energy required to reach the top: "<<frogJump(n-1,height,dp)<<endl;
    return 0;
}