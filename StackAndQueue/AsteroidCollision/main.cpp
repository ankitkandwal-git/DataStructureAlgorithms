#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    int n = asteroids.size();
    stack<int>stk;
    for(int i=0;i<n;i++){
        if(asteroids[i]>0){
            stk.push(asteroids[i]);
        }else{
            while(!stk.empty() &&stk.top()>0 && stk.top() <abs(asteroids[i])){
                stk.pop();
            }
            if(!stk.empty() && stk.top() == abs(asteroids[i])){
                stk.pop();
            }else if(stk.empty() || stk.top() < 0){
                stk.push(asteroids[i]);
            }
        }
    }
    vector<int>res;
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    int n;
    cout<<"Enter number of asteroids: ";
    cin>>n;
    vector<int>asteroids(n);
    cout<<"Enter the asteroids: ";
    for(int i=0;i<n;i++){
        cin>>asteroids[i];
    }
    vector<int>res = asteroidCollision(asteroids);
    cout<<"Remaining asteroids after collision: ";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}