#include<bits/stdc++.h>
using namespace std;

struct Delivery {
    int id;
    int deadline;
    int payment;
};

bool cmp(Delivery a, Delivery b){
    return a.payment > b.payment;
}

vector<int> deliverySchedule(vector<Delivery>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end(), cmp);
    int maxDeadline = 0;
    for(int i=0 ;i<n;i++){
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }
    vector<int>slots(maxDeadline+1,-1);
    int totalPayment = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        int j = arr[i].deadline;
        while(j>0){
            if(slots[j]==-1){
                slots[j] = arr[i].id;
                totalPayment += arr[i].payment;
                count++;
                break;
            }
            else{
                j--;
            }
        }
        if(count==maxDeadline){
                break;
        }
    }
    return {count, totalPayment};
}

int main(){
    int n;
    cin>>n;
    vector<Delivery>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].id>>arr[i].deadline>>arr[i].payment;
    }
    vector<int>ans = deliverySchedule(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}