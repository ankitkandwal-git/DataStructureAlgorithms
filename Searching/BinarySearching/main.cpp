#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n ,int target, int arr[]){
    int high = n-1;
    int low = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;  
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin >> target;
    cout << binarySearch(n, target, arr);
}