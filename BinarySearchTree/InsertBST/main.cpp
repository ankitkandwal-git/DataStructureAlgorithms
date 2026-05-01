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

Node* insert(Node* root,int val){
    if(root==NULL) return new Node(val);
    Node* cur = root;
    while(true){
        if(val<cur->data){
            if(cur->left==NULL){
                cur->left = new Node(val);
                break;
            }
            cur = cur->left;
        }
        else{
            if(cur->right==NULL){
                cur->right = new Node(val);
                break;
            }
            cur = cur->right;
        }
    }
    return root;
}
int main(){
    Node* root = NULL;
    root = insert(root,5);
    insert(root,3);
    insert(root,7);
    insert(root,2);
    insert(root,4);
    insert(root,6);
    insert(root,8);

    return 0;
}