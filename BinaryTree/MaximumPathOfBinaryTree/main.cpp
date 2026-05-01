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


int maxPathSum(Node* root,int &ans){
    if(!root) return 0;
    int leftPath = max(0,maxPathSum(root->left,ans));
    int rightPath = max(0,maxPathSum(root->right,ans));
    ans = max(ans,root->data+leftPath+rightPath);
    return root->data + max(leftPath,rightPath);
}
int main(){
    int n;
    cout<<"Enter the size of binary tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order: ";
    queue<Node*> q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        Node* newNode = new Node(val);
        if(!root){
            root = newNode;
            q.push(root);
        }else{
            Node* parent = q.front();
            if(!parent->left){
                parent->left = newNode;
                q.push(newNode);
            }else if(!parent->right){
                parent->right = newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }
    int ans = INT_MIN;
    maxPathSum(root,ans);
    cout<<"Maximum path sum in the binary tree is: "<<ans<<endl;
    return 0;
}