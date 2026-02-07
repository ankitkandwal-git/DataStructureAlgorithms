#include<bits/stdc++.h>
using namespace std;

int rob(int n , vector<int>&arr){
    vector<int>dp(n,0);
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        int pick = arr[i] + dp[i-2];
        int notpick = dp[i-1];
        dp[i] = max(pick,notpick);
    }
    return dp[n-1];
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
    cout<<"Maximum amount that can be robbed: "<<rob(n,arr)<<endl;
    return 0;
}