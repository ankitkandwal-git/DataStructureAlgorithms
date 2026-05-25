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

int sumRootToLeaf(Node* root){
    if(root==NULL) return 0;
    queue<pair<Node*, int>>q;
    q.push({root,root->data});
    int sum = 0;
    while(!q.empty()){
        Node* temp = q.front().first;
        int val = q.front().second;
        q.pop();
        if(temp->left == NULL && temp->right==NULL){
            sum+=val;
        }
        if(temp->left!=NULL)q.push({temp->left,val*2+temp->left->data});
        if(temp->right!=NULL)q.push({temp->right,val*2+temp->right->data});
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter total number of Nodes: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order : ";
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
    int result = sumRootToLeaf(root);
    cout<<result;
    return 0;
}