#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    try {
        std::cout << "Attempting to create valid Bureaucrat..." << std::endl;
        Bureaucrat normal("Jaouad", 1);
        std::cout << "Success!" << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try {
        std::cout << "Attempting to create Bureaucrat with grade 0..." << std::endl;
        Bureaucrat invalid("Oops", 0);
        
        std::cout << "Success!" << std::endl; 
    } 
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    try {
        std::cout << "\nTesting modifiers and operator overload..." << std::endl;
        Bureaucrat boss("Hermes", 2);
        
        std::cout << boss << std::endl; // Tests your << overload
        
        boss.incrementGrade();
        std::cout << "After promotion: " << boss << std::endl;
        
        boss.incrementGrade(); // This should throw GradeTooHighException (1 -> 0)
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat boss("Hermes", 1);
        Bureaucrat intern("Fry", 150);

        // Create a form that requires grade 50 to sign and 20 to execute
        Form taxForm("Tax Form", 50, 20);

        std::cout << taxForm << std::endl; // Test Form's << operator

        // Intern tries to sign (Should fail)
        intern.signForm(taxForm);

        // Boss tries to sign (Should succeed)
        boss.signForm(taxForm);

        // Boss tries to sign AGAIN (Already signed)
        boss.signForm(taxForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}