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

int maximumLevelSum(Node* root){
    if(root==NULL) return 0;
    queue<Node*>q;
    q.push(root);
    int maxSum = INT_MIN;
    int maxLevel = 0;
    int currentLevel = 0;
    while(!q.empty()){
        int size = q.size();
        int sum = 0;
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            sum+=temp->data;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        if(sum>maxSum){
            maxSum = sum;
            maxLevel = currentLevel;
        }
        currentLevel++;
    }
    return maxLevel;
}

int main(){
    int n;
    cout<<"Enter the number of nodes in the binary tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order : ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        if(root==NULL){
            root = new Node(val);
        }else{
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp->left==NULL){
                    temp->left = new Node(val);
                    break;
                }else{
                    q.push(temp->left);
                }
                if(temp->right==NULL){
                    temp->right = new Node(val);
                    break;
                }else{
                    q.push(temp->right);
                }
            }
        }
    }
    int result = maximumLevelSum(root);
    cout<<"Maximum level sum in the binary tree is: "<<result<<endl;
    return 0;
}