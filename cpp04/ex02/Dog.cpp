#include "Dog.hpp"

Dog::Dog(): Animal() {
    this->type = "Dog";
    brain = new Brain();
    for (int i = 0; i < 100; ++i) {
        brain->setIdea(i, "eating cats");
    }
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

void Dog::print_ideas() const {
    for (int i = 0; i < 100; ++i) {
        std::cout << "Idea " << i << ": " << brain->getIdea(i) << std::endl;
    }
}