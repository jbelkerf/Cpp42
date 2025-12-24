#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
    this->_name = "Default_FragTrap";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default constructor called for " << this->getName() << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->_name = name;
    std::cout << "FragTrap Parameterized constructor called for " << this->getName() << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called for " << other.getName() << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap Copy assignment operator called for " << other.getName() << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called for " << this->getName() << std::endl;
}
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " is requesting a high five!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        this->energyPoints--;
        std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "FragTrap " << this->getName() << " has insufficient energy or hit points to attack." << std::endl;
    }
}