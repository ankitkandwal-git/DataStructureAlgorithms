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

vector<int>rightViewBT(Node*root){
    vector<int>ans;
    if(!root) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        int temp;
        for(int i=0;i<size;i++){
            Node* cur = q.front();
            q.pop();
            temp = cur->data;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(root == NULL){
            root = new Node(x);
        }
        else{
            Node* cur = root;
            while(true){
                if(x < cur->data){
                    if(cur->left == NULL){
                        cur->left = new Node(x);
                        break;
                    }
                    else{
                        cur = cur->left;
                    }
                }
                else{
                    if(cur->right == NULL){
                        cur->right = new Node(x);
                        break;
                    }
                    else{
                        cur = cur->right;
                    }
                }
            }
        }
    }
    vector<int> result = rightViewBT(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}