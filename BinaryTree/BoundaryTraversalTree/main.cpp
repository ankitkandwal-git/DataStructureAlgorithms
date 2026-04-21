#include<bits/stdc++.h>
using namespace std;

class BoundaryTreeTraversal{
    public:
    struct Node{
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        };
        bool isLeaf(Node* root){
            if(!root->left && !root->right) return true;
            return false;
        }
        void leftBoundary(Node* root,vector<int>&result){
            Node* cur = root->left;
            while(cur){
                if(!isLeaf(cur)) result.push_back(cur->data);
                if(cur->left) cur = cur->left;
                else cur = cur->right;
            }
        }
        void leafNode(Node* root,vector<int>&result){
            if(!isLeaf(root)){
                if(root->left) leafNode(root->left,result);
                if(root->right) leafNode(root->right,result);
            }
            else result.push_back(root->data);
        }
        void rightBoundary(Node* root,vector<int>&result){
            Node* cur = root->right;
            vector<int>temp;
            while(cur){
                if(!isLeaf(cur)) temp.push_back(cur->data);
                if(cur->right) cur = cur->right;
                else cur = cur->left;
            }
            int n = temp.size();
            for(int i=n-1;i>=0;i--){
                result.push_back(temp[i]);
            }
        }
        vector<int>boundary(Node* root){
            vector<int>ans;
            if(!root) return ans;
            if(!isLeaf(root)) ans.push_back(root->data);
            leftBoundary(root,ans);
            leafNode(root,ans);
            rightBoundary(root,ans);
            return ans;
        }
    };
};
int main(){
    BoundaryTreeTraversal bt;
    BoundaryTreeTraversal::Node* root = new BoundaryTreeTraversal::Node(1);
    root->left = new BoundaryTreeTraversal::Node(2);
    root->right = new BoundaryTreeTraversal::Node(3);
    root->left->left = new BoundaryTreeTraversal::Node(4);
    root->left->right = new BoundaryTreeTraversal::Node(5);
    root->right->left = new BoundaryTreeTraversal::Node(6);
    root->right->right = new BoundaryTreeTraversal::Node(7);
    
    vector<int> ans = root->boundary(root);
    for(int i : ans) cout << i << " ";
    return 0;

}