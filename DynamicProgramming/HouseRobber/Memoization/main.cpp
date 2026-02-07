#include<bits/stdc++.h>
using namespace std;

int houseRobber(int n, vector<int>arr,vector<int>&dp){
    if(n==0) return arr[0];
    if(n==1) return max(arr[0],arr[1]);
    if(dp[n] != -1) return dp[n];
    int robbed = arr[n] + houseRobber(n-2,arr,dp);
    int notRobbed = 0 + houseRobber(n-1,arr,dp);
    return dp[n] = max(robbed,notRobbed);   
}
int main(){
    int n;
    cout<<"Enter number of houses: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter amount of money in each house: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n,-1);
    int maxAmount = houseRobber(n-1,arr,dp);    
    cout<<"Maximum amount that can be robbed: "<<maxAmount<<endl;
    return 0;
}