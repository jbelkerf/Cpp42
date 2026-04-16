#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "               CREATING BUREAUCRATS" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    Bureaucrat boss("The Boss", 1);          // Can do everything
    Bureaucrat mid("Mid-level Manager", 45); // Can do Shrubbery and Robotomy (mostly)
    Bureaucrat noob("Intern Steve", 150);    // Can do nothing

    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << noob << std::endl;

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "               TESTING SHRUBBERY FORM" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    ShrubberyCreationForm shrubbery("Home");

    // Noob tries to execute before signing (Should fail: Not signed)
    noob.executeForm(shrubbery);

    // Noob tries to sign (Should fail: Grade too low)
    noob.signForm(shrubbery);

    // Mid signs it (Should succeed)
    mid.signForm(shrubbery);

    // Mid executes it (Should succeed and create Home_shrubbery file)
    mid.executeForm(shrubbery);

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "               TESTING ROBOTOMY FORM" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    RobotomyRequestForm robotomy("Bender");

    // Boss signs it
    boss.signForm(robotomy);

    // Execute multiple times to see the 50% random chance!
    std::cout << "\n--- Attempt 1 ---" << std::endl;
    boss.executeForm(robotomy);
    std::cout << "--- Attempt 2 ---" << std::endl;
    boss.executeForm(robotomy);
    std::cout << "--- Attempt 3 ---" << std::endl;
    boss.executeForm(robotomy);
    std::cout << "--- Attempt 4 ---" << std::endl;
    boss.executeForm(robotomy);

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "               TESTING PRESIDENTIAL FORM" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    PresidentialPardonForm pardon("Ford Prefect");

    // Mid tries to sign (Should fail: Requires 25, Mid is 45)
    mid.signForm(pardon);

    // Boss signs it (Success)
    boss.signForm(pardon);

    // Mid tries to execute (Should fail: Requires 5, Mid is 45)
    mid.executeForm(pardon);

    // Boss executes it (Success: Prints Zaphod Beeblebrox message)
    boss.executeForm(pardon);

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "               CLEANING UP (DESTRUCTORS)" << std::endl;
    std::cout << "-------------------------------------------------------\n"
              << std::endl;

    return 0;
}