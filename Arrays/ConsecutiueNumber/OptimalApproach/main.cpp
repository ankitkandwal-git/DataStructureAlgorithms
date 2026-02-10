#include<bits/stdc++.h>
using namespace std;

int consecutiveNumber(int n,int arr[]){
    int max = 0;
    int cur = 0;
    for(int i=0;i<n;i++){
        if(arr[i] ==1){
            cur++;
        }
        else if(max<cur){
            max = cur;
        }
        else{
            cur = 0;
        }
    }
    return max;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<consecutiveNumber(n,arr);
}