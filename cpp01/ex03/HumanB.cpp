#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->weapon = NULL;
    this->name = name;
}

void HumanB::attack(void){
    if (weapon != NULL)
        std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " no weapon found " << std::endl;
}


void HumanB::setWeapon(Weapon &weap){
    weapon = &weap;
}
