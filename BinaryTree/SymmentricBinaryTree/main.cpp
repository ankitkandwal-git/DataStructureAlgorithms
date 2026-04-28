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

bool checkSymmetry(Node* root1,Node* root2){
    if(!root1 && !root2) return true;
    if(!root1 && root2) return false;
    if(root1 && !root2) return false;
    if(root1->data != root2->data) return false;
    return checkSymmetry(root1->left,root2->right) && checkSymmetry(root1->right,root2->left);
}
bool isSymmetric(Node* root){
    if(!root) return true;
    return checkSymmetry(root->left,root->right);
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order: ";
    queue<Node*> q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val == -1) continue;
        Node* newNode = new Node(val);
        if(!root) {
            root = newNode;
            q.push(root);
        } else {
            Node* parent = q.front();
            if(!parent->left) {
                parent->left = newNode;
                q.push(newNode);
            } else {
                parent->right = newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }
    if(isSymmetric(root)) {
        cout<<"The tree is symmetric."<<endl;
    } else {
        cout<<"The tree is not symmetric."<<endl;
    }
}