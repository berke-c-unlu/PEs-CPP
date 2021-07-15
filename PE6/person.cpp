#include <iostream>
#include "person.h"

using namespace std;

Person::Person(const string &name, float balance, int age){
    if(!name.empty()){
        this->name = name;
        this->balance = balance;
        this->age = age;
    }
}

void Person::print_info(){
    std::cout << "Name: " << name << " " << "Age: " << age << std::endl;
}