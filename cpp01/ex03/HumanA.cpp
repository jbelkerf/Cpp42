#include "HumanA.hpp"

void HumanA::attack(void){
    std::cout << name << "  attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& Weap):name(name), weapon(Weap)
{}
