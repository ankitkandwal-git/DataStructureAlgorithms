#include<bits/stdc++.h>
using namespace std;

int secondLargestNumber(int arr[], int n){
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > largest){
            second_largest = largest;  
            largest = arr[i];
        }
        else if(arr[i] > second_largest && arr[i] < largest){
            second_largest = arr[i];
        }
    }
    return (second_largest == INT_MIN) ? -1 : second_largest;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The second largest element in the array is: "<<secondLargestNumber(arr,n);
    return 0;
}