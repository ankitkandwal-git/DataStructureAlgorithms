#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch == '^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return 0;
}

bool isOperand(char ch){
    return isalpha(ch) || isdigit(ch);
}

string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    int n = s.length();
    stack<char> stk;
    string output = "";
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            s[i] =')';
        }
        else if(s[i]==')'){
            s[i] = '(';
        }
    }
    for(int i=0;i<n;i++){
        if(isOperand(s[i])){
            output += s[i];
        }
        else if(s[i]=='('){
            stk.push(s[i]);
        }
        else if(s[i]==')'){
            while(!stk.empty() && stk.top() != '('){
                output += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            if(s[i]=='^'){
                while((!stk.empty() && priority(s[i])<= priority(stk.top()))){
                    output += stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
            else{
                while(!stk.empty() && priority(s[i])< priority(stk.top())){
                    output += stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
    }
    while(!stk.empty()){
        output += stk.top();
        stk.pop();
    }
    reverse(output.begin(), output.end());
    return output;
}
int main(){
    string s;
    cout<<"Enter the infix expression: ";
    getline(cin, s);
    cout<<"Prefix expression is: "<<infixToPrefix(s)<<endl;
}