#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
       string help(string s){
        int n = s.size();
        int i=0,j=1;
        string ans="";
        while(j<n){
            if(s[i]==s[j]){
                j++;
            }
            else{
                ans.append(to_string(j-i)+s[i]);
                i=j;
                j++;
            }
        }
        ans.append(to_string(j-i)+s[i]);
        return ans;
    }
    string countAndSay(int n){
        if(n==1) return "1";
        return help(countAndSay(n-1));
    }
};

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    Solution sol;
    cout<<"The "<<n<<"th term of the count and say sequence is: "<<sol.countAndSay(n)<<endl;
    return 0;
}