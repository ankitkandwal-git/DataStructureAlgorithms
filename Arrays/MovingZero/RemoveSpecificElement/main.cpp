#include<bits/stdc++.h>
using namespace std;

int removeElement(int n , int target, int arr[]){
    int k = 0;
    for(int i=0;i<n;i++){
        if(arr[i] != target){
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}
int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    removeElement(n,target,arr);
    for(int i=0; i<n-1 ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}