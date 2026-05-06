#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* predecessor(Node* root, int key){
    Node* pre = NULL;
    while(root){
        if(root->data<key){
            pre = root;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return pre;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the BST: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes: ";
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        root = insert(root, val);
    }
    int key;
    cout<<"Enter the key to find its predecessor: ";
    cin>>key;
    Node* pre = predecessor(root, key);
    if(pre){
        cout<<"Predecessor of "<<key<<" is "<<pre->data<<endl;
    }
    else{
        cout<<"No predecessor found for "<<key<<endl;
    }
}