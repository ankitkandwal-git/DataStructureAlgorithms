#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string expand(int i,int j,string s){
        int n = s.size();
        int left = i, right =j;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindromeSubStr(string s){
        string ans="";
        int n = s.size();
        for(int i=0;i<n;i++){
            string odd = expand(i,i,s);
            if(odd.size()>ans.size()) ans=odd;
            string even = expand(i,i+1,s);
            if(even.size()>ans.size()) ans=even;
        }
        return ans;
    }
};

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    Solution sol;
    string ans = sol.longestPalindromeSubStr(s);
    cout<<"Longest Palindromic Substring: "<<ans<<endl;
}