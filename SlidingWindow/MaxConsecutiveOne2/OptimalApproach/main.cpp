#include<bits/stdc++.h>
using namespace std;

class MaxConsecutiveOne2 {
    public:
    int findMaxConsecutiveOnes(vector<int>&nums){
        int left=0,right=0;
        int countZero = 0;
        int maxLength = 0;
        while(right<nums.size()){
            if(nums[right]==0){
                countZero++;
            }
            while(countZero>1){
                if(nums[left]==0){
                    countZero--;
                }
                left++;
            }
            maxLength = max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
};
int main(){
    MaxConsecutiveOne2 obj;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result = obj.findMaxConsecutiveOnes(nums);
    cout<<"The maximum number of consecutive 1's is: "<<result<<endl;
    return 0;
}