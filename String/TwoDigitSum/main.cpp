#include<bits/stdc++.h>
using namespace std;

class TwoDigitSum{
    public:
    int getMaxSum(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 100;
            n /= 100;
        }
        return sum;
    }
};

int main(){
    TwoDigitSum tds;
    int n;
    cin >> n;
    cout << tds.getMaxSum(n) << endl;
    return 0;
}