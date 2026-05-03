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

Node* deleteNode(Node* root,int key){
    if(!root) return root;
    if(key < root->data){
        root->left = deleteNode(root->left,key);
        return root;
    }
    else if(key>root->data){
        root->right = deleteNode(root->right,key);
        return root;
    }
    if(root->left==NULL){
        Node* temp = root->right;
        delete root;
        return temp;
    }
    if(root->right==NULL){
        Node* temp = root->left;
        delete root;
        return temp;
    }
    Node* cur = root->right;
    while(cur->left){
        cur = cur->left;
    }
    root->data = cur->data;
    root->right = deleteNode(root->right,cur->data);
    return root;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);
    int key = 3;
    root = deleteNode(root,key);
    return 0;
}