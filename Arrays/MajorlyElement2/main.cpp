#include<bits/stdc++.h>
using namespace std;

class MajorityElement2{
public:
    vector<int>majorElement(vector<int>&nums){
        int n = nums.size();
        vector<int>ans;
        int leader1=INT_MIN,leader2=INT_MIN;
        int maj1 = 0,maj2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != leader2 && maj1==0){
                leader1 = nums[i];
                maj1=1;
            }
            else if(nums[i]!=leader1 && maj2==0){
                leader2 = nums[i];
                maj2=1;
            }
            else if(nums[i]==leader1){
                maj1++;
            }
            else if(nums[i]==leader2){
                maj2++;
            }
            else{
                maj1--;
                maj2--;
            }
        }
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==leader1){
                count1++;
            }
            else if(nums[i]==leader2){
                count2++;
            }
        }
        if(count1>n/3){
            ans.push_back(leader1);
        }
        if(count2>n/3){
            ans.push_back(leader2);
        }
        return ans;
    }
};
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    MajorityElement2 obj;
    vector<int>result = obj.majorElement(nums);
    cout<<"The majority elements are: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}