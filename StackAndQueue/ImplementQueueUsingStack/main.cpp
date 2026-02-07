#include<bits/stdc++.h>
using namespace std;

class Queue{
    private: 
        stack<int>stk1;
        stack<int>stk2;
    public: 
        void push(int x){
            stk1.push(x);
        }
        void pop(){
            if(!stk2.empty()){
                stk2.pop();
            }
            else{
                while(!stk1.empty()){
                    stk2.push(stk1.top());
                    stk1.pop();
                }
                stk2.pop();
            }
        }
        int front(){
            if(!stk2.empty()){
                return stk2.top();
            }
            else{
                while(!stk1.empty()){
                    stk2.push(stk1.top());
                    stk1.pop();
                }
            }
            return stk2.top();
        }
        bool empty(){
            return stk1.empty() && stk2.empty();
        }
        int size(){
            return stk1.size() + stk2.size();
        }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<endl; 
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl; 
    cout<<q.empty()<<endl; 
    return 0;
}