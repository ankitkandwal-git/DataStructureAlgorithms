#include<bits/stdc++.h>
using namespace std;

class BeautyOfAllSubString{
    public:
       int help(vector<int>&arr){
          int mini = INT_MAX, maxi = 0;
          for(int i=0;i<26;i++){
            if(arr[i]!=0){
                mini = min(mini,arr[i]);
                maxi = max(maxi,arr[i]);
            }
        }
        return maxi-mini;
    }
    int beauty(string s){
        int n = s.size() , ans =0;
        for(int i=0;i<n;i++){
            vector<int>arr(26,0);
            for(int j=i;j<n;j++){
                arr[s[j]-'a']++;
                ans+=help(arr);
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    BeautyOfAllSubString obj;
    cout<<"The beauty of all substring is: "<<obj.beauty(s)<<endl;
    return 0;
}