#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    return isalpha(ch) || isdigit(ch);

}

string prefixTopostfix(string s){
    stack<string>stk;
    int n = s.length();
        for(int i=n-1;i>=0;i--){
        if(isOperand(s[i])){
            stk.push(string(1,s[i]));
        }
        else{
            string x = stk.top();
            stk.pop();
            string y = stk.top();
            stk.pop();
            string finalResult = x+y + s[i];
            stk.push(finalResult);
        }
    }
    return stk.top();
}

int main(){
    string s;
    cout<<"Enter Prefix Expreession: "; 
    getline(cin,s);
    cout<<"Postfix Expression :"<<prefixTopostfix(s)<<endl;
    return 0;
}