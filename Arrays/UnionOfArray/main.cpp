#include<bits/stdc++.h>
using namespace std;

vector<int>unionOfArray(int a[] , int b[] , int m,int n){
    int i=0 , j=0;
    vector<int>ans;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            if(ans.empty() || ans.back() != a[i]){
                ans.push_back(a[i]);
            };
            i++;
        }
        else{
            if(ans.empty() || ans.back() != b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    return ans;
}
int main(){
    int m,n;
    cin>>m>>n;
    int a[m],b[n];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int>ans = unionOfArray(a,b,m,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}