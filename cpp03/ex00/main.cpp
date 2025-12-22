#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "\n\033[34m--- TEST 1: Construction & Basic Actions ---\033[0m" << std::endl;
    {
        ClapTrap robot("CL4P-TP");
        
       
        robot.attack("Bandit"); 
        robot.takeDamage(5);    
        robot.beRepaired(3);    
    } 

    std::cout << "\n\033[34m--- TEST 2: Energy Drain ---\033[0m" << std::endl;
    {
        ClapTrap worker("WorkerBot");

        for (int i = 0; i < 11; i++) {
            std::cout << "Action " << i + 1 << ": ";
            worker.attack("Target Dummy");
        }
    }

    std::cout << "\n\033[34m--- TEST 3: Death Logic ---\033[0m" << std::endl;
    {
        ClapTrap victim("Victim");

        victim.takeDamage(9);  
        victim.takeDamage(5);  
        
        std::cout << "Attempting to repair while dead:" << std::endl;
        victim.beRepaired(10); 
        std::cout << "Attempting to attack while dead:" << std::endl;
        victim.attack("Ghost"); 
    }

    std::cout << "\n\033[34m--- TEST 4: Copies ---\033[0m" << std::endl;
    {
        ClapTrap original("Original");
        original.takeDamage(5); 

        ClapTrap copy(original); 
        std::cout << "Copy created. Testing independence..." << std::endl;
        
        copy.beRepaired(5); 
        original.takeDamage(100); 
        
        std::cout << "Check Copy status (should be alive):" << std::endl;
        copy.attack("Survivor");
    }

    return 0;
}