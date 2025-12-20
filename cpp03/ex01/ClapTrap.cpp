#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}
ClapTrap::ClapTrap(): _name(*(new std::string("Default"))), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed with default name." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy): _name(copy._name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage) {
    std::cout << "ClapTrap " << _name << " copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        _name = other._name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}



std::string ClapTrap::getName() const {
    return _name;
}



void ClapTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has insufficient energy or hit points to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hitPoints <= amount) {
        hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and is now destroyed!" << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage, remaining hit points: " << hitPoints << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount){
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points, total hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has insufficient energy or hit points to repair." << std::endl;
    }
}
