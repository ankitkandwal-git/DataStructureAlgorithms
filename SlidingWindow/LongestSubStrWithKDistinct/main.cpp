#include<bits/stdc++.h>
using namespace std;

class LongestSubStrWithKDistinct {
    public:
    int longestSubStr(string s,int k){
        int n = s.size();
        int i=0,j=0,ans=0;
        unordered_map<int,int>m;
        while(j<n){
            m[s[j]]++;
            if(m.size()>k){
                while(m.size()>k){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            else{
                ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};
int main(){
    LongestSubStrWithKDistinct l;
    string s = "eceba";
    int k = 2;
    cout<<l.longestSubStr(s,k)<<endl;
    return 0;
}