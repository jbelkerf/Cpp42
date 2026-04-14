#include <iostream>

class Bureaucrat
{
    protected:
        const std::string tname;
        int tgrade;
        Bureaucrat();

    public:
        class GradeTooLowException: public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "error too low";
                }
        };

        class GradeTooHighException: public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "error to hight";
                }
        };

        const std::string getName() const;
        int getGrade() const;
        Bureaucrat(std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &other);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();
};