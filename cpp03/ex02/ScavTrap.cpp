#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
    this->_name = _name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->getName() << " constructed." << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap() {
    this->_name = "Default_ScavTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->getName() << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
    std::cout << "ScavTrap " << other.getName() << " copy constructed." << std::endl;
   *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap " << other.getName() << " assigned." << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints <= 0) {
        std::cout << "ScavTrap " << this->getName() << " has no energy to attack." << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->getName() << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->getName() << " destructed." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}