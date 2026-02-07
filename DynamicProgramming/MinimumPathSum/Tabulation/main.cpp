#include<bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>&grid, int m , int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
            }
            else if(i<0 || j<0){
                dp[i][j] = INT_MAX;
            }
            else{
                int right = INT_MAX;
                int down = INT_MAX;
                if(i>0) right = dp[i-1][j];
                if(j>0) down = dp[i][j-1];
                dp[i][j] =  grid[i][j] + min(right,down);
            }
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int m ,n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<minimumPathSum(grid,m,n);
    return 0;
}