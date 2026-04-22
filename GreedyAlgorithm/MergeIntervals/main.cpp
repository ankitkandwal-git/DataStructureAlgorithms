#include<bits/stdc++.h>
using namespace std;

class MergeIntervals{
    public:
    vector<vector<int>>merge(vector<vector<int>>&intervals){
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        for(auto& i:intervals){
            if(ans.empty() || ans.back()[1]<i[0]){
                ans.push_back(i);
            }
            else{
                ans.back()[1] = max(ans.back()[1], i[1]);
            }
        }
        return ans;
    }
};
int main(){
    MergeIntervals m;
    int n;
    cout<<"Enter the number of intervals: ";
    cin>>n;
    vector<vector<int>>intervals(n,vector<int>(2));
    cout<<"Enter the intervals: "<<endl;
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    vector<vector<int>>mergedIntervals = m.merge(intervals);
    cout<<"Merged Intervals: "<<endl;
    for(const auto& interval: mergedIntervals){
        cout<<"["<<interval[0]<<", "<<interval[1]<<"] ";
    }
    cout<<endl;
    return 0;
}