#include<bits/stdc++.h>
using namespace std;

int frogJump(int n,vector<int>&height, vector<int>&dp){
    dp[0] = 0;
    dp[1] = abs(height[1]-height[0]);
    for(int i=2;i<n;i++){
        int s1 = abs(height[i]-height[i-1] ) + dp[i-1];
        int s2 = abs(height[i]-height[i-2]) + dp[i-2];
        dp[i] = min(s1,s2);
    }
    return dp[n-1];
}
int main(){
    int n;
    cout<<"Enter number of stones: ";
    cin>>n;
    vector<int>height(n);
    cout<<"Enter heights of stones: ";
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    vector<int>dp(n,-1);
    cout<<"Minimum energy required to reach stone "<<n-1<<" is: "<<frogJump(n,height,dp)<<endl;
    return 0;
}   