#include "Intern.hpp"

Intern::Intern(){
    std::cout << "an intern was created" << std::endl;
}

Intern::~Intern(){
    std::cout << "intern was fired" << std::endl;
}

AForm *Intern::makeburry(const std::string &formname, const std::string &target){
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makerobot(const std::string &formname, const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePardon(const std::string &formname, const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *(Intern::*funcs[3])(std::string target) = {
        &Intern::makeburry,
        &Intern::makerobot,
        &Intern::makePardon
    };
}
