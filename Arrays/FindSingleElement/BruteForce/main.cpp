#include<bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            return arr[i];
        }
    }
    return -1;
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
    cout<<findSingleElement(arr,n);
    return 0;
}