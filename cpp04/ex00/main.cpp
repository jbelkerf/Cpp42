#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
std::cout << dog->getType() << " " << std::endl;
std::cout << cat->getType() << " " << std::endl;
cat->makeSound(); 
dog->makeSound();
meta->makeSound();

std:: cout << "\n----------------" << std::endl;
const WrongAnimal* metaa = new WrongCat();
metaa->makeSound();
delete metaa;
std:: cout << "----------------\n" << std::endl;


delete meta;
delete dog;
delete cat;
return 0;
}