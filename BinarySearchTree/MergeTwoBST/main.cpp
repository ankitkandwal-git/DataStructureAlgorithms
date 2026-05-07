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

void pushLeft(Node* root,stack<Node*>&s){
    while(root!=NULL){
        s.push(root);
        root = root->left;
    }
}

vector<int>mergeTwoBST(Node* root1,Node* root2){
    stack<Node*>s1;
    stack<Node*>s2;
    vector<int>ans;
    pushLeft(root1,s1);
    pushLeft(root2,s2);
    while(!s1.empty() && !s2.empty()){
        if(s1.empty() || (!s2.empty() && s1.top()->data < s1.top()->data)){
            Node* temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);
            if(temp->right!=NULL){
                pushLeft(temp->right,s2);
            }
        }
        else{
            Node* temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            if(temp->right!=NULL){
                pushLeft(temp->right,s1);
            }
        }
    }
    return ans;
}
int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(1);
    root2->left = new Node(0);
    root2->right = new Node(3);

    vector<int>ans = mergeTwoBST(root1,root2);
    for(int i:ans){
        cout<<i<<" ";
    }
}