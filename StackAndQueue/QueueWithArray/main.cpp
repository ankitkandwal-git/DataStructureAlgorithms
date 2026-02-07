#include<bits/stdc++.h>
using namespace std;

class Queue{
    public : 
      int *arr;
      int size;
      int capacity;
      int front;
      int back;
        Queue(int n){
            capacity = n;
            arr = new int[capacity];
            size = 0;
            front = -1;
            back = -1;
        }
    void push(int n){
        if(size == capacity){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(size ==0){
            front =0;
            back =0;
        }
        else{
            back = (back+1)%capacity;
        }
        arr[back] = n;
        size ++;
    }
    
    void pop(){
        if(size ==0){
            cout<<"Oueue Underflow"<<endl;
            return ;
        }
        if(size == 1){
                front = -1;
                back = -1;
        }
        front = (front+1)%capacity;
        size --;
    }
    int frontElement(){
        if(size ==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
        return size == 0;
    }
};

int main(){
    Queue q(3);
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.frontElement()<<endl;
    q.pop();
    cout<<q.frontElement()<<endl;
    cout<<q.isEmpty()<<endl;
    q.pop();
    return 0;
}