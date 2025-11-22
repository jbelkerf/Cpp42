#include "HumanB.hpp"

void HumanB::attack(void){
    std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name){
    this->name = name;
}

void HumanB::setWeapon(Weapon &weap){

    weapon = &weap;
}
