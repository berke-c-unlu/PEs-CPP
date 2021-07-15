#include <iostream>
#include "apartment.h"
#include "owner.h"

using namespace std;

Apartment::Apartment(const string &property_name, int area, Owner *owner, int floor, bool having_elevator){
    if(owner != NULL){
        this->property_name = property_name;
        this->area = area;
        this->owner = owner;
        this->having_elevator = having_elevator;
        this->floor = floor;
        owner->add_property(this);
    }
    else{
        this->property_name = property_name;
        this->area = area;
        this->owner = NULL;
        this->having_elevator = having_elevator;
        this->floor = floor;
    }
}

float Apartment::valuate(){
    if(having_elevator == 1){
        return area *floor * 1.5;
    }
    return area * floor;
}