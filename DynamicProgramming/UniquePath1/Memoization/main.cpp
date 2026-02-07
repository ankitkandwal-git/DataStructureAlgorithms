#include<bits/stdc++.h>
using namespace std;
int uniquepath(int i,int j,vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int right = uniquepath(i,j-1,dp);
    int down = uniquepath(i-1,j,dp);
    return dp[i][j] = right + down;
}

int main(){
    int m ,n;
    cin>>m>>n;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<uniquepath(m-1,n-1,dp);
    return 0;
}