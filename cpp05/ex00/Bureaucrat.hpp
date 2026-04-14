#include <iostream>

class Bureaucrat
{
    protected:
        class bureauException: public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "error";
                }
        };

        const std::string tname;
        int tgrade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
};