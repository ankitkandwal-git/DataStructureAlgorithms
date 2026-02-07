#include<bits/stdc++.h>
using namespace std;

int samuraiAndFriend(int i, int j1 , int j2, vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    int m = grid.size();
    int n = grid[0].size();
    if(j1<0 || j2<0 || j1>=n || j2>=n){
        return INT_MIN;
    }
    if(i==m-1){
        if(j1==j2){
            return grid[i][j1];
        }else{
            return grid[i][j1] + grid[i][j2];
        }
    }
    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }
    int grid_value;
    if(j1==j2){
        grid_value = grid[i][j1];
    }
    else{
        grid_value = grid[i][j1] + grid[i][j2];
    }
    int grid_x[9];
    grid_x[0] = samuraiAndFriend(i+1,j1-1,j2-1,grid,dp);
    grid_x[1] = samuraiAndFriend(i+1,j1-1,j2,grid,dp);
    grid_x[2] = samuraiAndFriend(i+1,j1-1,j2+1,grid,dp);
    grid_x[3] = samuraiAndFriend(i+1,j1,j2-1,grid,dp);
    grid_x[4] = samuraiAndFriend(i+1,j1,j2,grid,dp);
    grid_x[5] = samuraiAndFriend(i+1,j1,j2+1,grid,dp);
    grid_x[6] = samuraiAndFriend(i+1,j1+1,j2-1,grid,dp);
    grid_x[7] = samuraiAndFriend(i+1,j1+1,j2,grid,dp);
    grid_x[8] = samuraiAndFriend(i+1,j1+1,j2+1,grid,dp);
    int max_value = *max_element(grid_x,grid_x+9);
    return dp[i][j1][j2] = grid_value + max_value;
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
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    cout<<samuraiAndFriend(0,0,n-1,grid,dp)<<endl;
}