#include<bits/stdc++.h>
using namespace std;

pair<int,int>twoSum(vector<int>&nums,int target,int n){
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int complement = target-nums[i];
        if(mp.find(complement)!= mp.end()){
            return {mp[complement],i};
        }
        mp[nums[i]] = i;
    }
    return {-1,-1};
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    pair<int,int>result = twoSum(nums,target,n);
    if(result.first != -1){
        cout<<"Indices: "<<result.first<<" "<<result.second<<endl;
    }else{
        cout<<"No solution found."<<endl;
    }
    return 0;
}