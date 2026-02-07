#include<bits/stdc++.h>
using namespace std;
int rob(int n , vector<int>&arr){
    int prev2 = 0;
    int prev1 = arr[0];
    int current = 0;
    for(int i=2;i<n;i++){
        int pick = arr[i] + prev2;
        int notpick = 0 + prev1;
        prev2 = prev1;
        prev1 = current;
        current = max(pick,notpick);
    }
    return prev1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<arr[0]<<endl;
        return 0;
    }
    int ans1 = rob(n-1,arr);
    int firstHouse = arr[0];
    arr[0] = 0;
    int ans2 = rob(n,arr);
    cout<<max(ans1,ans2)<<endl;
    return 0;
}   