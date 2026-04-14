#include<bits/stdc++.h>
using namespace std;

int countSubarrayWithTargetSum(vector<int>&arr,int target){
    int count = 0;
    int sum = 0;
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==target){
            count++;
        }
        count += mp[sum-target];
        mp[sum]++;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    int result = countSubarrayWithTargetSum(arr,target);
    cout<<"The count of subarrays with target sum is: "<<result<<endl;
    return 0;
}