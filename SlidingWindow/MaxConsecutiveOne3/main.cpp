#include<bits/stdc++.h>
using namespace std;

class MaxConsecutiveOne3{
    public:
    int findMaxOnes(vector<int>&arr,int k){
        int left=0,right=0;
        int maxOnes=0;
        int zeroCount=0;
        while(right<arr.size()){
            if(arr[right]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(arr[left]==0){
                    zeroCount--;
                }
                left++;
            }
            maxOnes=max(maxOnes,right-left+1);
            right++;
        }
        return maxOnes;
    }
};
int main(){
    MaxConsecutiveOne3 obj;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result=obj.findMaxOnes(arr,k);
    cout<<"The maximum number of consecutive 1's is: "<<result<<endl;
    return 0;
}