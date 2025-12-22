
#include "ScavTrap.hpp"
#include "FragTrap.hpp" 

int main(void)
{
    std::cout << "\n\033[34m--- TEST 1: SCAVTRAP (The Gatekeeper) ---\033[0m" << std::endl;
    {
        ScavTrap scav("Guardian");
        
        // ScavTrap Stats: 100 HP / 50 Energy / 20 Damage
        scav.attack("Intruder"); // Should deal 20 damage
        scav.guardGate();        // Special ability
    } // scav destroyed here

    std::cout << "\n\033[34m--- TEST 2: FRAGTRAP (The High-Fiver) ---\033[0m" << std::endl;
    {
        FragTrap frag("Fraggy");

        // FragTrap Stats: 100 HP / 100 Energy / 30 Damage
        // Note: Unless you overrode attack(), it will say "ClapTrap ... attacks",
        // but the damage value MUST be 30.
        frag.attack("Zombie"); 
        
        // Special ability (Exclusive to FragTrap)
        frag.highFivesGuys();
    } // frag destroyed here

    std::cout << "\n\033[34m--- TEST 3: TANKINESS CHECK ---\033[0m" << std::endl;
    {
        FragTrap tank("TankBot");
        
        // FragTrap starts with 100 HP. 
        // A normal ClapTrap (10 HP) would die instantly here.
        tank.takeDamage(50); 
        tank.beRepaired(20);
        // Should survive and repair successfully
    }

    std::cout << "\n\033[34m--- END OF TESTS ---\033[0m" << std::endl;
    return 0;
}