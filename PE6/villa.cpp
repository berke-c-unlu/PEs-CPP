#include <iostream>
#include "villa.h"
#include "owner.h"

using namespace std;

Villa::Villa(const string &property_name, int area, Owner *owner, int number_of_floors, bool having_garden){
    if(owner != NULL){
        this->property_name = property_name;
        this->area = area;
        this->owner = owner;
        this->number_of_floors = number_of_floors;
        this->having_garden = having_garden;
        owner->add_property(this);
    }
    else{
        this->property_name = property_name;
        this->area = area;
        this->owner = NULL;
        this->number_of_floors = number_of_floors;
        this->having_garden = having_garden;
    }
}

float Villa::valuate(){
    if(having_garden==1){
        return area * 10 * number_of_floors*2;
    }
    return area * 10 * number_of_floors;
}