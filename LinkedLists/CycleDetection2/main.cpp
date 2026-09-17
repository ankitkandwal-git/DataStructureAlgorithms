#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
Node* arrayToLL(int arr[], int n){
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

Node* cycleDetection(Node* head){
    Node* slow = head;
    Node* fast = slow->next;
    Node* temp = NULL;
    while(fast != NULL && fast->next != NULL){
        if(slow==fast){
            temp = slow;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return temp;
}
int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the linked list: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Node* head = arrayToLL(arr, n);
    printLL(head);
    Node* temp = cycleDetection(head);
    if(temp != NULL){
        cout<<"Cycle detected at node with data: "<<temp->data<<endl;
    }
    else{
        cout<<"No cycle detected"<<endl;
    }
    return 0;

}