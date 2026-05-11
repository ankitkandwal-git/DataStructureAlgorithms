#include<bits/stdc++.h>
using namespace std;

class FruitsAndBasket{
    public:
    int totalFruit(vector<int>&tree){
        int n = tree.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>m;
            for(int j=i;j<n;j++){
                m[tree[j]]++;
                if(m.size()>2){
                    break;
                }
                ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};

int main(){
    FruitsAndBasket obj;
    int n;
    cout<<"Enter the number of trees: ";
    cin>>n;
    vector<int>tree(n);
    cout<<"Enter the types of fruits on the trees: ";
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    int result = obj.totalFruit(tree);
    cout<<"Maximum number of fruits that can be collected: "<<result<<endl;
    return 0;
}