#include <iostream>
#include <string>
#include <vector>
#include "owner.h"

using namespace std;

Owner::Owner(){
    
}

Owner::Owner(const string &name, float balance){
    this->name = name;
    this->balance = balance;
}

void Owner::print_info(){
    
}

string &Owner::get_name(){
    return name;
}

void Owner::add_property(Property *property){
    if(property != NULL)
        properties.push_back(property);
}

void Owner::buy(Property *property, Owner *seller){
    
    bool contain = false;

    if(this->balance < property->valuate()){
        std::cout << "[BUY] Property: "<< property->get_name() <<" Value: "<< property->valuate() <<"$ " << seller->get_name() <<"--->"<<this->name << std::endl;
        std::cout << "[ERROR] Unaffordable  property"<<std::endl;
        return;
    }
    
    for(int i = 0 ; i < seller->properties.size() ; i++){
        if(seller->properties[i] == property) {
            seller->properties.erase(seller->properties.begin()+i);
            contain = true;
            break;
        }
    }
    
    if(!contain){
        std::cout << "[BUY] Property: "<< property->get_name() <<" Value: "<< property->valuate() <<"$ " << seller->get_name() <<"--->"<<this->name << std::endl;
        std::cout << "[ERROR] Transaction  on  unowned  property"<<std::endl;
        return;
    }
    
    else{
        this->balance -= property->valuate();
        this->add_property(property);
        seller->balance += property->valuate();

        property->set_owner(this);
        
        std::cout << "[BUY] Property: "<< property->get_name() <<" Value: "<< property->valuate() <<"$ " << seller->get_name() <<"--->"<<this->name << std::endl;
    }
}

void Owner::sell(Property *property, Owner *owner){
    
    bool contain = false;

    
    if(owner->balance < property->valuate()){
        std::cout << "[SELL] Property: "<< property->get_name() <<" Value: "<< property->valuate() <<"$ " << this->name <<"--->"<< owner->get_name() << std::endl;
        std::cout << "[ERROR] Unaffordable  property"<<std::endl;
        return;
    }
    
    for(int i = 0 ; i < properties.size() ; i++){
        if(properties[i] == property) {
            properties.erase(properties.begin()+i);
            contain = true;
            break;
        }
    }
    
    if(!contain){
        std::cout << "[SELL] Property: "<< property->get_name() <<" Value: "<< property->valuate() <<"$ " << this->name <<"--->"<< owner->get_name() << std::endl;
        std::cout << "[ERROR] Transaction  on  unowned  property"<<std::endl;
        return;
    }

    else{
        owner->balance -= property->valuate();
        owner->add_property(property);
        this->balance += property->valuate();
        
        property->set_owner(owner);
        
        std::cout << "[SELL] Property: "<< property->get_name() <<" Value: "<< property->valuate() <<"$ " << this->name <<"--->"<< owner->get_name() << std::endl;
    }
}

void Owner::list_properties(){
    std::cout << "Properties of " << name <<":"<<std::endl;
    std::cout << "Balance: " << balance <<"$"<<std::endl;
    for(int i = 0 ; i < properties.size() ; i++){
        std::cout << (i+1)<<". " << properties[i]->get_name()<<std::endl;
    }

}