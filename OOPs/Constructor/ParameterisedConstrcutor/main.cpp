#include <iostream>
#include <string>
using namespace std;
using namespace std;

class Car{
    public:
    string brand;
    int speed;

    Car(string a, int b){
        this->brand = a;
        this->speed = b;
    }
    void display(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};

int main(){
    Car c1("BMW", 200);
    c1.display();
    // c1.brand and c1.speed are already accessible if needed
    return 0;
}