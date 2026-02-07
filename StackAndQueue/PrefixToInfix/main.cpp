#include<bits/stdc++.h>
using namespace std; 

bool isOperand(char ch){
    return isalpha(ch) || isdigit(ch);
}

string prefixToInfix(string s){
    int n = s.length();
    stack<string>stk;
    for(int i=n-1;i>=0;i--){
        if(isOperand(s[i])){
            stk.push(string(1,s[i]));
        }
        else{
            string x = stk.top();
            stk.pop();
            string y = stk.top();
            stk.pop();
            stk.push('(' + x + s[i] + y + ')');
        }
    }
    return stk.top();
}

int main(){
    string s;
    cout<<"Enter Prefix Expression: ";
    cin>>s;
    cout<<"Infix Expression: "<<prefixToInfix(s)<<endl;
    return 0;
}