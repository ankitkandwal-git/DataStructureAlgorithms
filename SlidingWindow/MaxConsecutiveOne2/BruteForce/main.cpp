#include<bits/stdc++.h>
using namespace std;

class MaxConsecutiveOne2{
    public:
    int findMaxConsecutiveOnes(vector<int>&nums){
        int n = nums.size();
        int maxCount = 0;
        for(int i=0;i<n;i++){
            int zero = 0;
            for(int j=i;j<n;j++){
                if(nums[j] == 0){
                    zero++;
                }
                if(zero > 1){
                    break;
                }
                maxCount = max(maxCount, j-i+1);
            }
        }
        return maxCount;
    }
};

int main(){
    MaxConsecutiveOne2  obj;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }   
    int result = obj.findMaxConsecutiveOnes(nums);
    cout<<"The maximum number of consecutive 1's is: "<<result<<endl;
    return 0;
}