#include<bits/stdc++.h>
using namespace std;

class InsertInterval{
    public:
    vector<vector<int>>insert(vector<vector<int>>&timeSlot,vector<int>&newSlot){
        int i=0;
        int n= timeSlot.size();
        vector<vector<int>>ans;
        while(i<n && timeSlot[i][1]<newSlot[0]){
            i++;
        }
        int start = INT_MAX;
        int end = -1;
        while(i<n && timeSlot[i][0]<=newSlot[1]){
            if(start == INT_MAX){
                start = timeSlot[i][0];
            }
            end = timeSlot[i][1];
            i++;
        }
        start = min(start,newSlot[0]);
        end = max(end,newSlot[1]);
        ans.push_back({start,end});
        while(i<n){
            ans.push_back(timeSlot[i]);
            i++;
        }
        return ans;
    }
};

int main(){
    InsertInterval obj;
    vector<vector<int>>timeSlot = {{1,3},{6,9}};
    vector<int>newSlot = {2,5};
    vector<vector<int>>ans = obj.insert(timeSlot,newSlot);
    for(auto it: ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}