#include<bits/stdc++.h>
using namespace std;

class ReverseInteger{
    public:
     void reverseInt(int num){
        int x = 0;
        int lastDigit;
        while(num!=0){
            lastDigit = num%10;
            x = x*10 + lastDigit;
            num = num/10;   
        } 
        cout<<x;
    }
};
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    ReverseInteger obj;
    obj.reverseInt(num);
    return 0;
}