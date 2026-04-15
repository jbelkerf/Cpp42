#include "RobotomyRequestForm.hpp"

RobotomyResquestForm::RobotomyResquestForm(std::string target):AForm("RobotomyResquestForm",72,45)
{
    std::cout << "RobotomyResquestForm has been created" << std::endl;
    _target = target;
}

RobotomyResquestForm::RobotomyResquestForm(const RobotomyResquestForm &other): AForm("RobotomyResquestForm", 72, 45) {
    *this = other;
}

RobotomyResquestForm &RobotomyResquestForm::operator=(const RobotomyResquestForm &other){
    this->_target = other._target;
    return *this;
}

RobotomyResquestForm::~RobotomyResquestForm()
{
    std::cout << "RobotomyResquestForm has been eliminated" << std::endl;
}

void RobotomyResquestForm::execute(const Bureaucrat &executor) const{
    //to be done using random
    std::cout << executor.getName() << std::endl;
}
