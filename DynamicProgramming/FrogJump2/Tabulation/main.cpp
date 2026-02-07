#include<bits/stdc++.h>
using namespace std;

int frogJump(int n,vector<int>&height, int k){
    vector<int>dp(n);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int minSteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0){
                int jump = dp[i-j] + abs(height[i]-height[i-j]);
                minSteps = min(minSteps,jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<frogJump(n,height,k)<<endl;
    return 0;
}