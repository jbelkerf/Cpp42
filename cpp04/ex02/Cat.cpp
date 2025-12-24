#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    brain = new Brain();
    for (int i = 0; i < 100; ++i) {
        brain->setIdea(i, "eating mouses");
    }
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

void Cat::print_ideas() const {
    for (int i = 0; i < 100; ++i) {
        std::cout << "Idea " << i << ": " << brain->getIdea(i) << std::endl;
    }
}