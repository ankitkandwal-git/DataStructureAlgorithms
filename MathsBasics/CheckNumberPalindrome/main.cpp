#include<bits/stdc++.h>
using namespace std;

class CheckNumberPalindrome{
    public:
    void checkPalindrome(int num){
        int x = 0;
        int lastDigit;
        while(num !=0){
            lastDigit = num%10;
            x  = x*10+lastDigit;
            num = num/10;
        }
        if(x==num){
            cout<<"The number is a palindrome.";
        }
        else{
            cout<<"The number is not a palindrome.";
        }
    }
};
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    CheckNumberPalindrome obj;
    obj.checkPalindrome(num);
    return 0;
}