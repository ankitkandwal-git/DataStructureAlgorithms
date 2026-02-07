// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.


#include<bits/stdc++.h>
using namespace std;

class MinStack{
    private: 
       stack<pair<int,int>>stk;
       int min;
    
    public : 
       MinStack(){
        min = 100000000;
       }
    void push(int x){
        if(stk.empty()){
            stk.push({x,x});
            min = x;
        }
        else{
            if(x<stk.top().second){
                stk.push({x,x});
                min = x;
            }
            else{
                stk.push({x,stk.top().second});
            }
        }
    }
    void pop(){
        if(stk.empty()) return ;
        stk.pop();
    }
    
    int top(){
        return stk.top().first;
    }
    int getMin(){
        return stk.top().second;
    }
};
int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl; 
    minStack.pop();
    cout<<minStack.top()<<endl;    
    cout<<minStack.getMin()<<endl; 
    return 0;
}