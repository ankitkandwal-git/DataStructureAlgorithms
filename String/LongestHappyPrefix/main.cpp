#include<bits/stdc++.h>
using namespace std;

class HappyPrefix{
    public:
    string longestPrefix(string s){
        int n = s.size();
        vector<int>lps(n,0);
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j]){
                lps[j] = i+1;
                i++;
                j++;
            }
            else {
                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else{
                    i = lps[i-1];
                }
            }
        }
        return s.substr(0,lps[n-1]);
    }
};

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    HappyPrefix hp;
    cout<<"Longest Happy Prefix: "<<hp.longestPrefix(s)<<endl;
}