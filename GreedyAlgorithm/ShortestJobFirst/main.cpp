#include<bits/stdc++.h>
using namespace std;

class ShortJobFirst{
    public:
    int findWaitingTime(vector<int>&waitingTime){
        int n = waitingTime.size();
        sort(waitingTime.begin(), waitingTime.end());
        int totalWaitingTime = 0;
        long long int currentTime = 0;
        for(int i=0;i<n;i++){
            totalWaitingTime += currentTime;
            currentTime += waitingTime[i];
        }
        return totalWaitingTime/n;
    }
};

int main(){
    ShortJobFirst obj;
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    vector<int> waitingTime(n);
    cout<<"Enter the waiting time for each job: ";
    for(int i=0;i<n;i++){
        cin>>waitingTime[i];
    }
    int totalWaitingTime = obj.findWaitingTime(waitingTime);
    cout<<"Total waiting time: "<<totalWaitingTime<<endl;
}