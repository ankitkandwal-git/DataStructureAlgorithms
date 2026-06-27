#include<bits/stdc++.h>
using namespace std;

class MergeKSortedArrays{
    public:
    vector<int>mergeKArrays(vector<vector<int>>&arr,int k){
        using pp = pair<int,pair<int,int>>;
        priority_queue<pp,vector<pp>,greater<pp>>minHeap;
        for(int i=0;i<k;i++){
            minHeap.push({arr[i][0],{i,0}});
        }
        vector<int>result;
        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            result.push_back(curr.first);
            int i = curr.second.first;
            int j = curr.second.second;
            if(j<k-1){
                minHeap.push({arr[i][j+1],{i,j+1}});
            }
        }
        return result;
    }
};

int main(){
    MergeKSortedArrays obj;
    int k;
    cout<<"Enter the number of sorted arrays: ";
    cin>>k;
    int m;
    cout<<"Enter the size of each sorted array: ";
    cin>>m;
    vector<vector<int>>arr(k,vector<int>(m));
    cout<<"Enter the elements of each sorted array: ";
    for(int i=0;i<k;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<int>result = obj.mergeKArrays(arr,k);
    cout<<"The merged sorted array is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;

}