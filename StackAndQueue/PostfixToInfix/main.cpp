#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    return isalpha(ch) || isdigit(ch);
}

string postfixToInfix(string s){
    stack<string>stk;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(isOperand(s[i])){
            stk.push(string(1,s[i]));
        }
        else{
            string x = stk.top(); stk.pop();
            string y = stk.top(); stk.pop();
            string temp = "("+y + s[i] + x +")";
            stk.push(temp);
        }
    }
    return stk.top();
}

int main(){
    string postfix;
    cout<<"Enter Postfix Expression: ";
    cin>>postfix;
    string infix = postfixToInfix(postfix);
    cout<<"Infix Expression: "<<infix<<endl;
    return 0;
}