#include<bits/stdc++.h>
using namespace std;

void rotateArrayByK(int n , int k, int arr[]){
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i] = arr[i];
    }
    for(int i=k;i<n;i++){
        arr[i-k] = arr[i];
    }
    for(int i=0;i<k;i++){
        arr[n-k+i] = temp[i];
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rotateArrayByK(n,k,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}   