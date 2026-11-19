#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = null
    }
};

Node* arrayToLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* swapPairs(Node* head){
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    while(prev->next!=NULL && prev.next.next!=NULL){
        Node* first = prev->next;
        Node* second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }
    return dummy->next;
}
int main(){
    int n;
    cout<<"Enter the size of LL: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of LL: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    Node* head = arrayToLL(arr, n);
    head = swapPairs(head);
    printLL(head);
}