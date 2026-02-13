#include<bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(vector<int>&arr,int target,int n){
    int i =0;
    for(int j=1;j<n;j++){
        if(arr[i]+arr[j]==target){
            return {i,j};
            i++;
        }
    }
    return {-1,-1};
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int>ans = twoSum(arr,target,n);
    if(ans.first==-1){
        cout<<"No such pair exists"<<endl;
    }
    else{
        cout<<"Pair found at indices: "<<ans.first<<" and "<<ans.second<<endl;
    }
}