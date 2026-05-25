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

void mirror(Node* root){
    if(root==NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        swap(temp->left,temp->right);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the binary tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order (use -1 for NULL): ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        if(root==NULL){
            root = new Node(val);
        }else{
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp->left==NULL){
                    temp->left = new Node(val);
                    break;
                }else{
                    q.push(temp->left);
                }
                if(temp->right==NULL){
                    temp->right = new Node(val);
                    break;
                }else{
                    q.push(temp->right);
                }
            }
        }
    }
    mirror(root);
    cout<<"The mirrored binary tree in level order is: ";
    if(root == NULL){
        cout<<"Empty tree";
    } else {
        queue<Node*> q;
        q.push(root);
        bool first = true;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(!first) cout<<" ";
            cout<<temp->data;
            first = false;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    cout<<"\n";
    return 0;
}