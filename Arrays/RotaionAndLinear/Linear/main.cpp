#include<bits/stdc++.h>
using namespace std;

int linearSearch(int n , int target, int arr[]){
    for(int i=0;i<n;i++){
        if(arr[i]== target){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = linearSearch(n,target,arr);
    if(ans==-1){
        cout<<"Element not found in the array"<<endl;
    }
    else{
        cout<<"Element found at index: "<<ans<<endl;
    }
}