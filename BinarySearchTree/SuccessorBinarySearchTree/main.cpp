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

Node* successor(Node* root,int key){
    Node* succ = NULL;
    while(root != NULL){
        if(root->data > key){
            succ = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return succ;
}
int main(){
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    int key = 15;
    Node* succ = successor(root, key);
    if(succ != NULL){
        cout << "Successor of " << key << " is " << succ->data << endl;
    }
    else{
        cout << "No successor for " << key << endl;
    }

    return 0;
}