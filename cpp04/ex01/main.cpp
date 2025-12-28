#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* animals[4];
    for (int i = 0; i < 4; ++i) {
        if (i < 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    std::cout << "\n\n--- ANIMAL SOUNDS ---" << std::endl;
    for (int i = 0; i < 4; ++i) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }
    std::cout << "\n\n--- DEEP COPY TEST ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    } 
    std::cout << "\n\n--- END OF SCOPE ---" << std::endl;
    return 0;
}