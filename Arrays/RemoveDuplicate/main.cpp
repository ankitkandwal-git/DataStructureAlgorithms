#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(int n , int arr[]){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int length = removeDuplicate(n,arr);
    cout<<"Length of array after removing duplicates: "<<length<<endl;
    cout<<"Array after removing duplicates: ";
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}   