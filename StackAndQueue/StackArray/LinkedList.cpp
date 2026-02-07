//  Stack implementation using Linked List 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
       int data;
       Node* next;
       Node(int data){
              this->data = data;
              this->next = NULL;
       }
}; 

class Stack{
        public: 
           Node* top;
              Stack(){
                top = NULL;
              } 
      
    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }    
    void pop(){
        if(top ==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }else{
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }   
    int topElement(){
        if(top ==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }else{
            return top->data;
        }
    } 
    bool empty(){
        if(top==NULL) return true;
        return false;
    }
    int size(){
        int count = 0;
        Node* temp = top;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<"Top Element : "<<st.topElement()<<endl;
    cout<<"Stack Size :"<<st.size()<<endl;
    st.pop();
    st.pop();
    cout<<"Is Stack Empty :"<<(st.empty() ? "Yes":"No")<<endl;
    cout<<"Stack Size :"<<st.size()<<endl;
    return 0;
}