#include "Zombie.hpp"

int main(){
    Zombie *a = zombieHorde(4, "jbelkerf");
    for (int i = 0; i< 4;i++){
        a[i].announce();
    }
    delete []a;//! to be searched
}