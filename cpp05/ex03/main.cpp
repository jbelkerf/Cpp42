#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "               TESTING THE INTERN" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    Intern someRandomIntern;
    AForm *rrf;
    AForm *scf;
    AForm *ppf;
    AForm *unknown;

    std::cout << "\n--- Intern attempts to create valid forms ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

    std::cout << "\n--- Intern attempts to create an invalid form ---" << std::endl;
    unknown = someRandomIntern.makeForm("super secret form", "Nobody");

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "               TESTING BUREAUCRAT EXECUTION" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    Bureaucrat boss("The Boss", 1); // Grade 1 can sign and execute everything

    std::cout << boss << std::endl
              << std::endl;

    if (rrf)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // Must delete to avoid memory leaks!
        std::cout << std::endl;
    }

    if (scf)
    {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
        std::cout << std::endl;
    }

    if (ppf)
    {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
        std::cout << std::endl;
    }

    // Just in case the unknown form was accidentally allocated
    if (unknown)
    {
        delete unknown;
    }

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "               CLEANING UP DESTRUCTORS" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    return 0;
}