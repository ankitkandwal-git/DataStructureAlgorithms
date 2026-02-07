#include<bits/stdc++.h>
using namespace std;

int maximumPathSum(int m , int n , vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(n<0 || n >= (int)grid[0].size()) return INT_MIN;
    if(m == (int)grid.size() - 1) return grid[m][n];
    if(dp[m][n] != -1) return dp[m][n];
    int down = maximumPathSum(m+1,n,grid,dp);
    int diagonalLeft = maximumPathSum(m+1,n-1,grid,dp);
    int diagonalRight = maximumPathSum(m+1,n+1,grid,dp);
    int temp = max(diagonalLeft,diagonalRight);
    return dp[m][n] = grid[m][n] + max(temp,down);
}
int main(){
    int m , n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int maxSum = INT_MIN;
    for(int j=0;j<n;j++){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        maxSum = max(maxSum,maximumPathSum(0,j,grid,dp));
    }
    cout<<maxSum<<endl;
    return 0;
}