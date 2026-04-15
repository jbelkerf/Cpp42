#include "PresidentialPardonForm.hpp"

PresidentialPardonFrom::PresidentialPardonFrom(std::string target) : AForm("PresidentialPardonFrom", 25,5)
{
    std::cout << "PresidentialPardonFrom created " << std::endl;
    target = target;
}

PresidentialPardonFrom::PresidentialPardonFrom(PresidentialPardonFrom const &other) : AForm("PresidentialPardonFrom", 25, 5)
{
    std::cout << "PresidentialPardonFrom coppied" << std::endl;
    *this = other;
}

PresidentialPardonFrom &PresidentialPardonFrom::operator=(PresidentialPardonFrom const &other){
    _target = other._target;
    return *this;
}

void PresidentialPardonFrom::execute(Bureaucrat const & executor) const {

    std::cout << _target << " has benn pardoned by "<< executor.getName() << std::endl;
}

PresidentialPardonFrom::~PresidentialPardonFrom(){
    std::cout << "the PresidentialPardonFrom has been eliminated";
}