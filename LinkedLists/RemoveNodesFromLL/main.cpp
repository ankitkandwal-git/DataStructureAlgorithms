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

Node* arrayToLL(int arr[], int n){
    if(n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1; i<n; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* removeNodes(Node* head){
    if(head==NULL) return NULL;
    Node* temp = head;
    while(temp->next !=NULL){
        if(temp->data<temp->next->data){
            temp->data = temp->next->data;
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else{
            temp = temp->next;
        
        } 
    }
    return head;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the linked list: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the linked list: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr, n);
    cout<<"The linked list is: ";
    printLL(head);
    head = removeNodes(head);
    cout<<"The modified linked list is: ";
    printLL(head);
    return 0;

}