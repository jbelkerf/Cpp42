#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "\n\033[34m--- TEST 1: Construction Chaining ---\033[0m" << std::endl;
    {
        ScavTrap guard("Guardian");
        
        std::cout << "\n\033[34m--- TEST 2: The Special 'guardGate' Ability ---\033[0m" << std::endl;
        
        guard.guardGate();

        std::cout << "\n\033[34m--- TEST 3: Overridden Attack (Damage 20) ---\033[0m" << std::endl;
        
        guard.attack("Intruder");

        std::cout << "\n\033[34m--- TEST 4: Tankiness (HP 100) ---\033[0m" << std::endl;
        guard.takeDamage(50); 
        guard.beRepaired(10); 
        
        std::cout << "\n\033[34m--- TEST 5: Destruction Chaining ---\033[0m" << std::endl;
    }

    return 0;
}