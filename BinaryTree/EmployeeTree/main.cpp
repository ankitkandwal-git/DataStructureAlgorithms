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

bool isEmployee(Node*root){
    if(root==NULL) return false;
    queue<Node*>q;
    q.push(root);
    int level = 1;
    int currentLevelNodes = 1;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}