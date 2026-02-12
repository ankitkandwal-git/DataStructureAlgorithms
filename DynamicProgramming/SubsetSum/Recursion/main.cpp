#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int total , int n , int k,int arr[]){
    if(total==0) return true;
    if(i==0){
        if(arr[0]==total) return true;
        else return false;
    } 
    bool notPick = solve(i-1,total,n,k,arr);
    bool pick = false;
    if(arr[i]<=total) pick = solve(i-1,total-arr[i],n,k,arr);
    else pick = false;
    return  pick || notPick;
}

bool subsetSumToK(int n, int k, int arr[]){
    return solve(n-1,k,n,k,arr);
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<subsetSumToK(n,k,arr)<<endl;
}