#include<bits/stdc++.h>
using namespace std;

class BinarySubarrayWithSumK{
    public:
    int f(vector<int>&arr,int k){
        int n = arr.size();
        int i=0,j=0,sum=0,res=0;
        while(j<n){
            sum+=arr[j];
            while(sum>k){
                sum -=arr[i];
                i++;
            }
            res = j-i+1;
            j++;
        }
        return res;
    }
    int BSWS(vector<int>&arr,int k){
        return f(arr,k) - f(arr,k-1);
    }
};
int main(){
    BinarySubarrayWithSumK obj;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result = obj.f(arr,k);
    cout<<"The length of the longest subarray with sum k is: "<<result<<endl;
    return 0;
}