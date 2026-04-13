#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&arr){
    int n = arr.size();
    int j = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            j = i;
            break;
        }
    }
    if(j==-1){
        reverse(arr.begin(),arr.end());
        return;
    }
    int k;
    for(int i=n-1;i>j;i--){
        if(arr[i]>arr[j]){
            k = i;
            break;
        }
    }
    swap(arr[j], arr[k]);
    reverse(arr.begin() + j + 1, arr.end());

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
    nextPermutation(arr);
    cout<<"Next permutation: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}