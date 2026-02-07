#include<bits/stdc++.h>
using namespace std;

vector<int>nextGreaterElement(vector<int>&arr){
    int n = arr.size();
    stack<int>stk;
    vector<int>ans(n,-1);
    for(int i=2*n-1;i>=0;i--){
        while(!stk.empty() && arr[i%n]>=stk.top()){
            stk.pop();
        }
        if(i<n && !stk.empty()){
            ans[i] = stk.top();
        }
        stk.push(arr[i%n]);
    }
    return ans;
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
    vector<int>result = nextGreaterElement(arr);
    cout<<"Next Greater Elements are: ";
    for(int x: result){
        cout<<x<<" ";
    }
    return 0;
}