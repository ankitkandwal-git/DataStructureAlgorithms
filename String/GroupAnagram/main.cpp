#include<bits/stdc++.h>
using namespace std;

class GroupAnagram{
    public:
    vector<vector<string>>groupAnagram(vector<string>&str){
        int n = str.size();
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(auto s:str){
            vector<int>arr(26,0);
            for(auto c:s){
                arr[c-'a']++;
            }
            string key = "";
            for(int i:arr){
                key+="*"+to_string(i);
            }
            m[key].push_back(s);
        }
        for(auto& pair:m){
            ans.push_back(pair.second);
        }
        return ans;
    }
};

int main(){
    GroupAnagram g;
    vector<string>str;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        str.push_back(s);
    }
    vector<vector<string>>ans = g.groupAnagram(str);
    for(auto v:ans){
        for(auto s:v){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}