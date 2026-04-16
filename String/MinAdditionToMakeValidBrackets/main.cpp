#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
      int minAddToMakeValid(string s){
        int count = 0, ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') count++;
            else if(count==0) ans+=1;
            else count-=1;
        }
        ans+=count;
        return ans;
    }
};

int main(){
    Solution s;
    string str;
    cout<<"Enter the string of brackets: ";
    cin>>str;
    cout<<"The answer is "<<s.minAddToMakeValid(str)<<endl;
    return 0;
}