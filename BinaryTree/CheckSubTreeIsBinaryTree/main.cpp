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

bool isSubTree(Node* root1,Node* subRoot){
    if(root1 == NULL && subRoot == NULL){
        return true;
    }
    if(root1 == NULL || subRoot == NULL){
        return false;
    }
    if(root1->data == subRoot->data){
        return isSubTree(root1->left,subRoot->left) && isSubTree(root1->right,subRoot->right);
    }
    return isSubTree(root1->left,subRoot) || isSubTree(root1->right,subRoot);
}
bool isValid(Node* root,Node* subRoot){
    if(!root) return false;
    if(!subRoot) return true;
    if(root->data == subRoot->data){
        return isValid(root->left,subRoot->left) && isValid(root->right,subRoot->right);
    }
    return isValid(root->left,subRoot) || isValid(root->right,subRoot);
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the first tree: ";
    cin>>n;
    int m;
    cout<<"Enter the number of nodes in the second tree: ";
    cin>>m;
    Node* root1 = NULL;
    Node* root2 = NULL;
    cout<<"Enter the values of the first tree: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(root1 == NULL){
            root1 = new Node(val);
        }
        else{
            Node* temp = root1;
            while(temp != NULL){
                if(val < temp->data){
                    if(temp->left == NULL){
                        temp->left = new Node(val);
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = new Node(val);
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }
    cout<<"Enter the values of the second tree: ";
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        if(root2 == NULL){
            root2 = new Node(val);
        }
        else{
            Node* temp = root2;
            while(temp != NULL){
                if(val < temp->data){
                    if(temp->left == NULL){
                        temp->left = new Node(val);
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = new Node(val);
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }
    if(isSubTree(root1,root2)){
        cout<<"The second tree is a subtree of the first tree."<<endl;
    }
    else{
        cout<<"The second tree is not a subtree of the first tree."<<endl;
    }
}