#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root,int k,int &count,int &ans){
    if(root==NULL) return;
    inorder(root->left,k,count,ans);
    count++;
    if(count==k){
        ans = root->val;
        return;
    }
    inorder(root->right,k,count,ans);
}
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int ans = -1;
    inorder(root,k,count,ans);
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;
    cout<<kthSmallest(root,k)<<endl;
    return 0;
}