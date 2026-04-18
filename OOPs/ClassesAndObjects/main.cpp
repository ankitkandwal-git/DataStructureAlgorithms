#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    string brand;
    string model;
    int speed;

    void display(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Speed: "<<speed<<" km/h"<<endl;
    }
};

int main(){
    Car bmw;
    bmw.brand = "BMW";
    bmw.model = "X5";
    bmw.speed = 250;
    bmw.display();
    return 0;
}