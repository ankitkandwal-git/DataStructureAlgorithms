#include<bits/stdc++.h>
using namespace std;

int uniquePath2(int m, int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(m<0 || n<0) return 0;
    if(grid[m][n]==1) return 0;
    if(m==0 && n==0) return 1;
    if(dp[m][n]!= -1) return dp[m][n];
    int right = uniquePath2(m-1,n,grid,dp);
    int down = uniquePath2(m,n-1,grid,dp);
    return dp[m][n] = right + down;
}
int main(){
    int m,n;
    cout<<"Enter the number of rows and columns: ";
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n,0));
    cout<<"Enter the grid (0 for empty cell and 1 for obstacle): "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int result = uniquePath2(m-1,n-1,grid,dp);
    cout<<"Number of unique paths: "<<result<<endl;
}