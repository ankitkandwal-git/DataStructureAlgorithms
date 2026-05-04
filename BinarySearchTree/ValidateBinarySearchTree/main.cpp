#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void inorder(TreeNode* root, long mini , long maxi, bool &ans){
    if(root==NULL) return;
    inorder(root->left,mini,root->val,ans);
    if(root->val<=mini || root->val>=maxi) ans = false;
    inorder(root->right,root->val,maxi,ans);
}
bool isValidBST(TreeNode* root) {
    bool ans = true;
    inorder(root,LONG_MIN,LONG_MAX,ans);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    TreeNode* root = NULL;
    cout<<"Enter the values of the nodes in level order (use -1 for NULL):; ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        if(root==NULL) {
            root = new TreeNode(val);
            continue;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left==NULL){
                temp->left = new TreeNode(val);
                break;
            }
            else q.push(temp->left);
            if(temp->right==NULL){
                temp->right = new TreeNode(val);
                break;
            }
            else q.push(temp->right);
        }
    }
    if(isValidBST(root)) cout<<"The tree is a valid Binary Search Tree."<<endl;
    else cout<<"The tree is not a valid Binary Search Tree."<<endl;
}