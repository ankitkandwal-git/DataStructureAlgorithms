#include<bits/stdc++.h>
using namespace std;

bool maxHeapValidation(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left<n && arr[left]>arr[i]){
            return false;
        }
        if(right<n && arr[right]>arr[i]){
            return false;
        }
    }
    return true;
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
    if(maxHeapValidation(arr)){
        cout<<"The given array is a valid max heap."<<endl;
    }
    else{
        cout<<"The given array is not a valid max heap."<<endl;
    }
    return 0;
}