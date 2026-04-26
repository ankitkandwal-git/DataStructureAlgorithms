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

vector<int>bottomView(Node* root){
    if(root==NULL) return{};
    vector<int>ans;
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto x = q.front();
        Node* cur = x.first;
        int col = x.second;
        q.pop();
        mp[col] = cur->data;
        if(cur->left) q.push({cur->left,col-1});
        if(cur->right) q.push({cur->right,col+1});
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the binary tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order : ";
    queue<Node*> q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        Node* newNode = new Node(val);
        if(root==NULL){
            root = newNode;
            q.push(root);
        }else{
            Node* parent = q.front();
            if(parent->left==NULL){
                parent->left = newNode;
                q.push(newNode);
            }else{
                parent->right = newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }
    vector<int> result = bottomView(root);
    cout << "Bottom view of the binary tree: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
}