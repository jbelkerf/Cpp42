#include <iostream>
#ifndef CLAPTRAP_HPP   
#define CLAPTRAP_HPP
class ClapTrap {
    private:
        std::string &_name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap(const std::string& name);


        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
};
#endif