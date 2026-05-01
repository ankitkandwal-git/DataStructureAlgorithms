#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool childrenSumProperty(Node* root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    int childSum = 0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;
    if(root->data != childSum) return false;
    return childrenSumProperty(root->left) && childrenSumProperty(root->right);
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order: ";
    queue<Node*> q;
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        Node* newNode = new Node(val);
        if(root==NULL){
            root = newNode;
            q.push(root);
        }else{
            Node* parent = q.front();
            if(parent->left==NULL){
                parent->left = newNode;
                q.push(newNode);
            }else if(parent->right==NULL){
                parent->right = newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }
    if(childrenSumProperty(root)) cout<<"The children sum property."<<endl;
    else cout<<"The tree does not satisfy the children sum property."<<endl;
}