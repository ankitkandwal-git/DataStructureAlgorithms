#include<bits/stdc++.h>
using namespace std;
int uniquepathh(int m , int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int i=0;i<=m-1;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<=n-1;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int m ,n;
    cin>>m>>n;
    cout<<uniquepathh(m,n);
    return 0;
}