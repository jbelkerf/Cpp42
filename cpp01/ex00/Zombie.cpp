#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::~Zombie(){
    std::cout << "Zombie --> " << name << " elemenated" << std::endl;
}
Zombie::Zombie(std::string name){
    this->name = name;
}