#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&nums,int n){
    int sum1 = 0;
    for(int i=0;i<n;i++){
        sum1 +=nums[i];
    }
    int sum2 = (n*(n+1))/2;
    return sum2-sum1;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){   
        cin>>arr[i];
    }
    vector<int>nums(arr,arr+n);
    cout<<"The missing number is: "<<missingNumber(nums,n)<<endl;
    return 0;
}