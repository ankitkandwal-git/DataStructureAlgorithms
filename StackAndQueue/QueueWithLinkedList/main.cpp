#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
      int data;
      Node* next;
        Node(int value){
            data = value;
            next = NULL;
        }
};

class Queue{
    private: 
       Node* front;
       Node* back;
    public: 
      Queue(){
          front = NULL;
          back = NULL;
      }
    
    void push(int value){
        Node* temp = new Node(value);
        if(front ==NULL){
            front = temp;
            back = temp;
        }
        else{
            back->next = temp;
            back = temp;

        }
    }
    void pop(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    int frontElement(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        return front ==NULL;
    }

    int size(){
        int count = 0;
        Node* temp = front;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"Front element: "<<q.frontElement()<<endl; 
    cout<<"Queue size: "<<q.size()<<endl; 
    q.pop();
    cout<<"Front element after pop: "<<q.frontElement()<<endl;
    cout<<"Is queue empty? "<<(q.isEmpty() ? "Yes" : "No")<<endl;
    cout<<"The size of queue is: "<<q.size()<<endl;
    return 0;
}