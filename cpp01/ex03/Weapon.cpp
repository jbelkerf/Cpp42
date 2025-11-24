#include "Weapon.hpp"

Weapon::Weapon(std::string name){
    setType(name);
}

const std::string& Weapon::getType(void)
{
    std::string &ref = this->type;
    return ref;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

