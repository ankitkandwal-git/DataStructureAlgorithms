#include<bits/stdc++.h>
using namespace std;

class PrintALlDigits{
    public:
    void printDigits(int n){
        if(n==0) return;
        int lastDigit = n%10;
        int remainingDigits = n/10;
        printDigits(remainingDigits);
        cout << lastDigit << " ";
    }
};
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    PrintALlDigits obj;
    cout << "Digits in the number are: ";
    obj.printDigits(n);
    return 0;
}