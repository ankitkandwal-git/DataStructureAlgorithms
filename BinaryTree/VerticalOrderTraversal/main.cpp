#include<bits/stdc++.h>
using namespace std;

class VOT{
public:
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
    Node* buildTree(vector<int>& nodes){
        if(nodes.size() == 0 || nodes[0] == -1) return NULL;

        Node* root = new Node(nodes[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while(!q.empty() && i < nodes.size()){
            Node* cur = q.front();
            q.pop();
            if(nodes[i] != -1){
                cur->left = new Node(nodes[i]);
                q.push(cur->left);
            }
            i++;
            if(i < nodes.size() && nodes[i] != -1){
                cur->right = new Node(nodes[i]);
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }

    vector<vector<int>> VerticalOrder(Node* root){
        map<int,map<int,vector<int>>> m;
        queue<pair<Node*,pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            Node* cur = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            m[col][row].push_back(cur->data);

            if(cur->left){
                q.push({cur->left,{row+1,col-1}});
            }
            if(cur->right){
                q.push({cur->right,{row+1,col+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto &col : m){
            vector<int> temp1;
            for(auto &row : col.second){
                auto temp2 = row.second;
                sort(temp2.begin(), temp2.end());
                temp1.insert(temp1.end(), temp2.begin(), temp2.end());
            }
            ans.push_back(temp1);
        }

        return ans;
    }
};

int main(){
    VOT v;
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    vector<int> nodes(n);
    cout<<"Enter level order (-1 for NULL): ";
    for(int i=0;i<n;i++){
        cin>>nodes[i];
    }
    VOT::Node* root = v.buildTree(nodes);

    vector<vector<int>> result = v.VerticalOrder(root);

    for(auto &col : result){
        for(int val : col){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}