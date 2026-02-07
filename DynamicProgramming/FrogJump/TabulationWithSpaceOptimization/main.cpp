#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int>&height){
    int prior_1 = 0;
    int prior_2 = abs(height[1]-height[0]);
    int current = 0;
    for(int i=2;i<n;i++){
        int jump1 = abs(height[i]-height[i-1]) + prior_2;
        int jump2 = abs(height[i]-height[i-2]) + prior_1;
        current = min(jump1,jump2);
        prior_1 = prior_2;
        prior_2 = current;
    }
    return current;
}
int main(){
    int n;
    cout<<"Enter number of stairs: ";
    cin>>n;
    vector<int>height(n);
    cout<<"Enter heights of stairs: ";
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<"Minimum energy used by frog to reach last stair is: "<<frogJump(n,height)<<endl;
    return 0;
}