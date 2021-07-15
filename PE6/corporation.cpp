#include <iostream>
#include "corporation.h"

using namespace std;

Corporation::Corporation(const string &name, float balance, string address){
    if(!name.empty()){
        this->name = name;
        this->balance = balance;
        this->address = address;
    }
}

void Corporation::print_info(){
    std::cout << "Name: " << name << " " << "Address: " << address<< std::endl;
}