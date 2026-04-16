#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm",72,45)
{
    std::cout << "RobotomyRequestForm has been created" << std::endl;
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("RobotomyRequestForm", 72, 45) {
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    this->_target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm has been eliminated" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
    this->isReadyForExecute(executor);
    std::cout << "* BZZZZZT! VRRRRRRR! DRRRRRR! *" << std::endl;
    std::srand((unsigned)time(NULL));
    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
    }
}
