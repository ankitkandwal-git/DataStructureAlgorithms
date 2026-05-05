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

Node* LCA(Node* root, int p,int q){
    while(root){
    if(root==NULL) return NULL;
    if(p < root->data && q<root->data) root = root->left;
    else if(p > root->data && q>root->data) root = root->right;
    else return root;
  }
  return root;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(root==NULL) root = new Node(val);
        else{
            Node* curr = root;
            while(true){
                if(val < curr->data){
                    if(curr->left==NULL){
                        curr->left = new Node(val);
                        break;
                    }
                    else curr = curr->left;
                }
                else{
                    if(curr->right==NULL){
                        curr->right = new Node(val);
                        break;
                    }
                    else curr = curr->right;
                }
            }
        }
    }
    int p,q;
    cout<<"Enter the values of the two nodes: ";
    cin>>p>>q;
    Node* ans = LCA(root,p,q);
    if(ans) cout<<"The lowest common ancestor of "<<p<<" and "<<q<<" is: "<<ans->data<<endl;
    else cout<<"No common ancestor found."<<endl;
    
}