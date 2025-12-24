
#include "ScavTrap.hpp"
#include "FragTrap.hpp" 

int main(void)
{
    std::cout << "\n\033[34m--- TEST 1: SCAVTRAP (The Gatekeeper) ---\033[0m" << std::endl;
    {
        ScavTrap scav("Guardian");
        
        scav.attack("Intruder"); 
        scav.guardGate();      
    } 

    std::cout << "\n\033[34m--- TEST 2: FRAGTRAP (The High-Fiver) ---\033[0m" << std::endl;
    {
        FragTrap frag("Fraggy");

        frag.attack("Zombie"); 
        
        frag.highFivesGuys();
    } 

    std::cout << "\n\033[34m--- TEST 3: TANKINESS CHECK ---\033[0m" << std::endl;
    {
        FragTrap tank("TankBot");
        
        tank.takeDamage(50); 
        tank.beRepaired(20);
    }

    std::cout << "\n\033[34m--- END OF TESTS ---\033[0m" << std::endl;
    return 0;
}