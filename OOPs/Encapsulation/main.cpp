#include<iostream>
#include<string>
using namespace std;
class Account{
    // Account balance
    private:
    double balance;
    public:
    void setBalance(double amount){
        balance = amount;
    }
    double display(){
        return balance;
    }
};

int main(){
    Account acc;
    acc.setBalance(1000.0);
    cout<<"Balance: "<<acc.display()<<endl;
}