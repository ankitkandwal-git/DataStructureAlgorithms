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

Node* sortLLAscending(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp = head;
    while(temp!=NULL){
        Node* temp2 = temp->next;
        while(temp2!=NULL){
            if(temp->data > temp2->data){
                swap(temp->data,temp2->data);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    head = sortLLAscending(head);
    cout<<"Sorted Linked List: ";
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;

}