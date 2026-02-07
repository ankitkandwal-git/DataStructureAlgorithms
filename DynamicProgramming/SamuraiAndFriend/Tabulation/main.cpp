#include<bits/stdc++.h>
using namespace std;

int samuraiAndFriend(int i, int j1 , int j2,int m, int n, vector<vector<int>>&grid){
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));

    for(int i=m-1;i>=0;i--){
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(i==m-1){
                    if(j1==j2) dp[i][j1][j2] = grid[i][j1];
                    else dp[i][j1][j2 ] = grid[i][j1]+grid[i][j2];
                }
                else{
                    vector<int>x;
                    for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){
                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;
                            if(nj1>=0 && nj1<n && nj2>=0 && nj2<n){
                                x.push_back(dp[i+1][nj1][nj2]);
                            }
                        }
                    }
                    int max_next = *max_element(x.begin(),x.end());
                    int curr = (j1==j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    dp[i][j1][j2] = curr + max_next;
                }
            }
        }
    }
    return dp[0][0][n-1];
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
    cout<<samuraiAndFriend(0,0,n-1,m,n,grid);
}