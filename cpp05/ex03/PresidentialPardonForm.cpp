#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25,5)
{
    std::cout << "PresidentialPardonForm created " << std::endl;
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm coppied" << std::endl;
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    this->isReadyForExecute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "the PresidentialPardonForm has been eliminated" << std::endl;
}