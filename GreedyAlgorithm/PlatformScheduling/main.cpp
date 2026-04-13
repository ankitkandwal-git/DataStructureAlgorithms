#include<bits/stdc++.h>
using namespace std;

int platformSchedule(vector<int>&arr,vector<int>&dep){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0,j=0,count=0,ans=0;
    while(i<n){
        if(arr[i]<dep[j]){
            count++;
            ans = max(ans,count);
            i++;
        }
        else{
            count--;
            j++;
        }
    }
    return ans;
}

int main(){
    int m;
    cout<<"Enter the number of trains: ";
    cin>>m;
    vector<int>arr(m),dep(m);
    cout<<"Enter the arrival times of the trains: ";
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    cout<<"Enter the departure times of the trains: ";
    for(int i=0;i<m;i++){
        cin>>dep[i];
    }
    int result = platformSchedule(arr,dep);
    cout<<"Minimum number of platforms required: "<<result<<endl;
    return 0;
}