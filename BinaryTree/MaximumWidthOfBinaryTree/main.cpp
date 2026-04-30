#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxWidthOfBT(TreeNode* root){
    if(root==NULL) return 0;
    queue<pair<TreeNode*,long long>>q;
    q.push({root,0});
    int ans = -1;
    while(!q.empty()){
        int size = q.size();
        int start_index = q.front().second;
        int width = 0;
        for(int i=0;i<size;i++){
            TreeNode* node = q.front().first;
            long long cur = q.front().second;
            long long index = cur-start_index;
            q.pop();
            width = index+1;
            if(node->left) q.push({node->left,2*index+1});
            if(node->right) q.push({node->right,2*index+2}); 
        }
        ans = max(ans,width);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of Tree: ";
    cin>>n;
    TreeNode* root = NULL;
    cout<<"Enter the values of Tree: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(root==NULL){
            root = new TreeNode(val);
        }
        else{
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left==NULL){
                    cur->left = new TreeNode(val);
                    break;
                }
                else{
                    q.push(cur->left);
                }
                if(cur->right==NULL){
                    cur->right = new TreeNode(val);
                    break;
                }
                else{
                    q.push(cur->right);
                }
            }
        }
    }   
    cout<<"Maximum Width of Binary Tree: "<<maxWidthOfBT(root)<<endl;
}