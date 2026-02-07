#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int prev2 = 0;
    int prev1 = 1;
    int current = 0;
    for(int i=2;i<=n;i++){
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Fibonacci number at position "<<n<<" is: "<<fib(n)<<endl;
    return 0;
}