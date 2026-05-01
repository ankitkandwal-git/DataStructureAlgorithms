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
Node* searchBST(Node* root,int key){
    if(root==NULL) return NULL;
    while(root!=NULL){
        if(root->data==key) return root;
        else if(root->data>key) root=root->left;
        else root=root->right;
    }
    return root;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the BST: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(root==NULL) root = new Node(val);
        else{
            Node* temp = root;
            while(true){
                if(temp->data>val){
                    if(temp->left==NULL){
                        temp->left = new Node(val);
                        break;
                    }
                    else temp=temp->left;
                }
                else{
                    if(temp->right==NULL){
                        temp->right = new Node(val);
                        break;
                    }
                    else temp=temp->right;
                }
            }
        }
    }
    int key;
    cout<<"Enter the key to search: ";
    cin>>key;
    Node* ans = searchBST(root,key);
    if(ans==NULL) cout<<"Key not found in the BST."<<endl;
    else cout<<"Key found in the BST: "<<ans->data<<endl;
    return 0;
}