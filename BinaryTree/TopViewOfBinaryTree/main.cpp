#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int>topView(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    map<int,int>m;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto x = q.front();
        Node* cur = x.first;
        int col = x.second;
        q.pop();
        if(m.find(col)==m.end()){
            m[col] = cur->data;
        }
        if(cur->left){
            q.push({cur->left,col-1});
        }
        if(cur->right){
            q.push({cur->right,col+1});
        }
    }
    for(auto i:m){
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
    queue<Node**>q;
    q.push(&root);
    for(int i=0;i<n;i++){
        Node** cur = q.front();
        q.pop();
        int val;
        cin>>val;
        if(val!=-1){
            *cur = new Node(val);
            q.push(&((*cur)->left));
            q.push(&((*cur)->right));
        }
    }
    vector<int>result = topView(root);
    cout<<"Top view of the binary tree: ";
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}