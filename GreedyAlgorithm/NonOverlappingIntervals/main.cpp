#include<bits/stdc++.h>
using namespace std;

class NonOverlappingIntervals{
    public:
    static bool helper(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int minOverlapping(vector<vector<int>>&arr){
        int n = arr.size();
        sort(arr.begin(),arr.end(),helper);
        int count = 1;
        int end = arr[0][1];
        for(int i=1;i<n;i++){
            if(arr[i][0]>=end){
                count++;
                end = arr[i][1];
            }
        }
        return n-count;
    }
};
int main(){
    int n;
    cout<<"Enter the number of intervals: ";
    cin>>n;
    NonOverlappingIntervals obj;
    vector<vector<int>>arr(n,vector<int>(2));
    cout<<"Enter the intervals: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    cout<<"Minimum number of intervals to remove: "<<obj.minOverlapping(arr)<<endl;
    return 0;
}