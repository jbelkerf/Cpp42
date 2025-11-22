#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
    std::string name;
    Weapon & weapon;

public:
    HumanA(std::string name, Weapon& Weap):name(name), weapon(Weap){}
    void attack();
};
#endif