#include "Zombie.hpp"


int main()
{
    Zombie *a = newZombie("a");
    a->announce();
    randomChump("b");
    delete a;
}