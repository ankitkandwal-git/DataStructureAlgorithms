// Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
// An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.

#include<bits/stdc++.h>
using namespace std;

bool balancedParenthesis(string s){
    stack<char>st;
    for(size_t i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false; 
            char top = st.top();
            if((s[i]==')' && top=='(') || (s[i]=='}' && top=='{') || (s[i]==']' && top=='[')){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()) return true;
    return false;
}
int main(){
    string s;
    cout<<"Enter the Parenthesis String: ";
    cin>>s;
    if(balancedParenthesis(s)){
        cout<<"Balanced Parenthesis is: True"<<endl;
    }
    else{
        cout<<"Not Balanced Parenthesis is: False"<<endl;
    }
}

//  c:\Users\lenovo\DSA\StackAndQueue\BalancedParenthesis\output\main.exe