#include "Bureaucrat.hpp"
#include "Form.hpp"

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

Bureaucrat::Bureaucrat() : tname("Default"), tgrade(150) {
    std::cout << "Default Bureaucrat created" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "deleting the bereaucrat" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "coping bureaucrat" << std::endl;
    tgrade = other.tgrade;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}


void Bureaucrat::incrementGrade(){
    if (this->tgrade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->tgrade -= 1;
}

void Bureaucrat::decrementGrade(){
    if (this->tgrade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->tgrade += 1;
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


void Bureaucrat::signForm(Form &form){
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getFormName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getFormName() << "  " << e.what() << std::endl;
    }
    
}