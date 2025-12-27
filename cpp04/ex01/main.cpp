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
    for (int i = 0; i < 4; ++i) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }
    std::cout << "--- DEEP COPY TEST ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic; // Copy constructor
    } // tmp is destroyed here. If shallow, basic's brain is deleted!
    std::cout << "--- END OF SCOPE ---" << std::endl;
    // basic is destroyed here. If shallow, double-free error occurs.
    return 0;
}