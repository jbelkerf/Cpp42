
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scav("SC4V-TP");

    scav.attack("Target Dummy");
    scav.guardGate();
    scav.takeDamage(30);

    ScavTrap scav2(scav);

    ScavTrap ss("dd") ;

    ss = scav2;
    
}