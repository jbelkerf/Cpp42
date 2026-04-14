#include "Bureaucrat.hpp"


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

    return 0;
}