#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* arrayToDoublyLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

Node* reverseDLL(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head = arrayToDoublyLL(arr,n);
    cout<<"Original Doubly Linked List: ";
    printLL(head);
    head = reverseDLL(head);
    cout<<"Reversed Doubly Linked List: ";
    printLL(head);
    return 0;
}