#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int n , int arr[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==0){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    moveZeroes(n,arr);
    cout<<"The array after moving zeroes to the end is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}