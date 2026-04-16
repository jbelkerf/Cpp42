#include "Intern.hpp"

Intern::Intern(){
    std::cout << "an intern was created" << std::endl;
}

Intern::Intern(const Intern &other){
    std::cout << "intern copied" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other){
    (void)other;
    return *this;
}

Intern::~Intern(){
    std::cout << "intern was fired" << std::endl;
}

AForm *Intern::makeburry(const std::string &target){
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makerobot(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePardon(const std::string &target)
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
    AForm *(Intern::*funcs[3])(const std::string &target) = {
        &Intern::makeburry,
        &Intern::makerobot,
        &Intern::makePardon
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*funcs[i])(target);
        }
    }
    std::cerr << "Intern couldn't create form: " << formName << " (Unknown Form)" << std::endl;
    return NULL;
}
