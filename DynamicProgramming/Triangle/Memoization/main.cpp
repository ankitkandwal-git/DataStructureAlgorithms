#include<bits/stdc++.h>
using namespace std;

int triangleMinimumPath(int i, int j , vector<vector<int>>&triangle,vector<vector<int>>&dp , int n){
    if(i==n-1){
        return triangle[n-1][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down = triangle[i][j] + triangleMinimumPath(i+1,j,triangle,dp,n);
    int diagonal = triangle[i][j] + triangleMinimumPath(i+1,j+1,triangle,dp,n);
    return dp[i][j] = min(down,diagonal);
}
int  main(){
    int n;
    cin>>n;
    vector<vector<int>> triangle(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>triangle[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<triangleMinimumPath(0,0,triangle,dp,n)<<endl;
    return 0;
}