#include<bits/stdc++.h>
using namespace std;

int linearSearch(int n , int target, int arr[]){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << linearSearch(n, target, arr);
    return 0;
}