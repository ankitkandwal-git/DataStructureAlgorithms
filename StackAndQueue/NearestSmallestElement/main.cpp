#include<bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int>&arr){
    int n  = arr.size();
    vector<int>ans(n,-1);
    stack<int>stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && stk.top() >= arr[i]){
            stk.pop();
        }
        if(!stk.empty()){
            ans[i] = stk.top();
        }
        stk.push(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    vector<int>result = NSE(arr);
    cout<<"Nearest Smaller Elements are:";
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
}