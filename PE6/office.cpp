#include <iostream>
#include "office.h"
#include "owner.h"

using namespace std;

Office::Office(const string &property_name, int area, Owner *owner, bool having_wifi, bool having_reception){
    if(owner != NULL){
        this->property_name = property_name;
        this->area = area;
        this->owner = owner;
        this->having_reception = having_reception;
        this->having_wifi = having_wifi;
        owner->add_property(this);
    }
    else{
        this->property_name = property_name;
        this->area = area;
        this->owner = NULL;
        this->having_reception = having_reception;
        this->having_wifi = having_wifi;
    }
}

float Office::valuate(){
    if(having_wifi == 1 && having_reception == 1){
        return 1.3*1.5*area*5;
    }
    else if(having_wifi == 1 && having_reception == 0){
        return 1.3*area*5;
    }
    else if(having_wifi == 0 && having_reception == 1){
        return 1.5*area*5;
    }
    return area*5;
}