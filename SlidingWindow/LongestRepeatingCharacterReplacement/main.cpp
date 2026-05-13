#include<bits/stdc++.h>
using namespace std;

class LongestRepeatingCharacterReplacement{
    public:
    int longestRepeat(string s,int k){
        int n = s.size();
        int i=0,j=0,ans=0,maxi=0;
        vector<int> count(26,0);
        while(j<n){
            count[s[j]-'A']++;
            maxi = max(maxi,count[s[j]-'A']);
            if(j-i+1-maxi>k){
                count[s[i]-'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
int main(){
    LongestRepeatingCharacterReplacement obj;
    int n;
    cout<<"Enter the size of the string: ";
    cin>>n;
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result = obj.longestRepeat(s,k);
    cout<<"The length of the longest substring is: "<<result<<endl;
}