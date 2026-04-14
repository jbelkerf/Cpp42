#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): tname(name)
{
    std::cout << "creating bureaucrat" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        tgrade = grade;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "deleting the bereaucrat" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "coping bureaucrat" << std::endl;
    tgrade = other.tgrade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): tname(other.tname){
    *this = other;
}

const std::string Bureaucrat::getName() const{
    return this->tname;
}

int Bureaucrat::getGrade() const{
    return this->tgrade;
}
