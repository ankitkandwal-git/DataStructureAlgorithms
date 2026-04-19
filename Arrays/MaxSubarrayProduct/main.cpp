#include<bits/stdc++.h>
using namespace std;

class MaxSubarrayProduct{
    public:
    int maxProduct(vector<int>&arr){
        int n = arr.size();
        int result = INT_MIN;
        int suffix = 1, prefix = 1;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;
            prefix *= arr[i];
            suffix *= arr[n-1-i];
            result = max(result, max(prefix, suffix));
        }
        return result;
    }
};

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    MaxSubarrayProduct msp;
    cout<<"The maximum product of a subarray is: "<<msp.maxProduct(arr)<<endl;
    return 0;
}