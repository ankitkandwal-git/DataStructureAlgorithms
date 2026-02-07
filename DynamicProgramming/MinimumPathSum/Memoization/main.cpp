#include<bits/stdc++.h>
using namespace std;

int minimumPathSum(int m , int n , vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(m<0 || n<0) return 1e9;
    if(m==0 && n==0) return grid[0][0];
    if(dp[m][n] != -1) return dp[m][n];
    int right = minimumPathSum(m-1,n,grid,dp);
    int down = minimumPathSum(m,n-1,grid,dp);
    return dp[m][n] = grid[m][n] + min(right,down);
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(m,vector<int>(n,-1));
    cout<<minimumPathSum(m-1,n-1,grid,dp)<<endl;
    return 0;
}