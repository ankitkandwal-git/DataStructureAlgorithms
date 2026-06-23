#include<bits/stdc++.h>
using namespace std;

class ConvertMinToMax{
    public:
    void heapify(int i,vector<int>&arr){
        int n = arr.size();
        int l = 2*i+1;
        int r = 2*i+2;
        int maxi = i;
        if(l<n && arr[l]>arr[maxi]) maxi = l;
        if(r<n && arr[r]>arr[maxi]) maxi = r;
        if(maxi!=i){
            swap(arr[i],arr[maxi]);
            heapify(maxi,arr);
        }
    }
    void minToMax(vector<int>&arr){
        int n = arr.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(i,arr);
        }
    }
};

int main(){
    ConvertMinToMax obj;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    obj.minToMax(arr);
    cout<<"The max heap is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}