#include <iostream>
#include <string>
using namespace std;
using namespace std;

class Student{
public:
    string name;
    int age;
    // constructor default
    Student(string name, int age){
        this->name = name;
        this->age = age;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main(){
    Student s1("Ankit", 21);
    s1.display();
    // s1.name and s1.age are already accessible if needed
    return 0;
}