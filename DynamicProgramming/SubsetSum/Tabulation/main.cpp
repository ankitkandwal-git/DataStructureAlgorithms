#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int n,int k,int arr[]){
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int total=1;total<=k;total++){
        if(total==arr[0]){
            dp[0][total]=1; 
        }
    }
    for(int i=1;i<n;i++){
        for(int total=1;total<=k;total++){
            bool notPick = dp[i-1][total];
            bool pick = false;
            if(arr[i]<=total){
                pick = dp[i-1][total-arr[i]];
            }
            else pick = false;
            dp[i][total] = pick || notPick;
        }
    }
    return dp[n-1][k];
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<subsetSum(n,k,arr)<<endl;
}