#include<bits/stdc++.h>
using namespace std;

int triangleMinPath(int m , int n,vector<vector<int>>&triangle){
    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dp[m-1][j] = triangle[m-1][j];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diag = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,diag);
        }
    }
    return dp[0][0];
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>triangle(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<=i;j++){
            cin>>triangle[i][j];
        }
    }
    cout<<triangleMinPath(m,n,triangle);
    return 0;
}