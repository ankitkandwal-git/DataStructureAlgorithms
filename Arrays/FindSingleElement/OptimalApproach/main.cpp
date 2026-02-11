#include<bits/stdc++.h>
using namespace std;

int singleElement(int n , int arr[]){
    int xor1 = 0;
    for(int i=0;i<n;i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
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
    cout<<"The single element in the array is : "<<singleElement(n,arr)<<endl;
}