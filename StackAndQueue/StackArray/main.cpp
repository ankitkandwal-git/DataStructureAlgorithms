#include <iostream>
using namespace std;

class Stack{
    int *arr;
    int capacity;
    int top;
    public : 
        Stack(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            top = -1;
        }
        ~Stack(){
            delete [] arr;
        }
    int push(int x){
        if(top<capacity-1){
            arr[++top] = x;
            return 0;
        } else{
            return -1;
        }
    }
    int pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }else{
            return arr[top--];
        }
    }
    bool empty() const{
        return top == -1;
    }
    int topElement() const{
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    int size() const{
        return top + 1;
    }
};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"Top Element: "<<st.topElement()<<endl;
    cout<<"Stack Size: "<<st.size()<<endl;
    cout<<"Popped Element: "<<st.pop()<<endl;
    cout<<"Is Stack Empty: "<<(st.empty() ? "Yes" : "No")<<endl;
    return 0;
}