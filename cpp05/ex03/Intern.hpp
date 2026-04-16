#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern{
    private:
        AForm *makePardon(const std::string &target);
        AForm *makeburry(const std::string &target);
        AForm *makerobot(const std::string &target);

    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& formName, const std::string& target);

};

#endif