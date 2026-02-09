#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionOfArray(int arr1[],int arr2[],int m,int n){
    int i=0,j=0;
    vector<int>ans;
    while(i<m && j<n){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}
int main(){
    int m,n;
    cin>>m>>n;
    int arr1[m],arr2[n];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    vector<int>ans=intersectionOfArray(arr1,arr2,m,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}