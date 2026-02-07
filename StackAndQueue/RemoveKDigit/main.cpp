#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num , int k){
    int n = num.size();
    stack<char>stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && k>0 && stk.top()>num[i]){
            stk.pop();
            k--;
        }
        stk.push(num[i]);
    }
    while(!stk.empty() && k!=0){
        stk.pop();
        k--;
    }
    string ans = "";
    while(!stk.empty()){
        ans+=stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    int idx = 0;
    while (idx < static_cast<int>(ans.size()) && ans[idx] == '0') idx++;
    ans = ans.substr(idx);
    if (ans.empty()) return "0";
    return ans;
}

int main() {
    string num;
    int k;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter k: ";
    cin >> k;
    cout << "Result: " << removeKdigits(num, k) << endl;
    return 0;
}