#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* arrayToLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return  head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* partitionLL(Node* head, int x){
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    Node* dummy = new Node(-1);
    Node* temp = head;
    while(temp != NULL){
        if(temp->data <=x){
            dummy->next = temp;
            dummy = dummy->next;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    int n;
    cout<<"Enter the size of LL: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the value of x: ";
    cin>>x;
    Node* head = arrayToLL(arr,n);
    head = partitionLL(head,x);
    printLL(head);
}
