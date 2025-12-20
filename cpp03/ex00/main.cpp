
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap_1("JJ");
    ClapTrap clap_2("GG");

    clap_1.attack(clap_2.getName());
    clap_2.takeDamage(5);

    ClapTrap clone(clap_2);
    clone.beRepaired(3);
    return 0;
}