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

void path(Node* root,vector<int>&v,vector<vector<int>>&ans){
    if(root==NULL) return;
    v.push_back(root->data);
    if(root->left==NULL && root->right == NULL){
        ans.push_back(v);
        v.pop_back();
        return;
    }
    path(root->left,v,ans);
    path(root->right,v,ans);
    v.pop_back();
}
vector<vector<int>>binaryTreePaths(Node* root){
    vector<vector<int>>ans;
    vector<int>v;
    if(root==NULL) return ans;
    path(root,v,ans);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the binary tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order: ";
    queue<Node*> q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        Node* newNode = new Node(val);
        if(root==NULL){
            root = newNode;
            q.push(root);
        }
        else{
            Node* parent = q.front();
            if(parent->left==NULL){
                parent->left = newNode;
                q.push(newNode);
            }
            else if(parent->right==NULL){
                parent->right = newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }
    vector<vector<int>> ans = binaryTreePaths(root);
    cout<<"All root-to-leaf paths in the binary tree:"<<endl;
    for(auto path : ans){
        cout<<"{";
        for(int i=0;i<path.size();i++){
            cout<<path[i];
            if(i<path.size()-1) cout<<",";
        }
        cout<<"} ";
    }
    cout<<endl;
}