#include <iostream>
#include "property.h"
#include "owner.h"

using namespace std;

Property::Property(){
}

Property::Property(const string &property_name, int area, Owner *owner){
    if(owner != NULL){
        this->property_name = property_name;
        this->area = area;
        this->owner = owner;
        owner->add_property(this);
    }
    else{
        this->property_name = property_name;
        this->area = area;
        this->owner = NULL;
    }
}

void Property::set_owner(Owner *owner){
    this->owner = owner;
}

float Property::valuate(){
    return 0.0;
}

string &Property::get_name(){
    return this->property_name;
}

void Property::print_info(){
    if(!owner){
        std::cout << property_name << " " << "(" << area << " m2) Owner: No owner" << std::endl;
    }
    else{
        std::cout << property_name << " " << "(" << area << " m2) Owner: " << owner->get_name()<< std::endl;
    }
}