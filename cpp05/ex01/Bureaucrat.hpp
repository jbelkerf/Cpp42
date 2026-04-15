#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
class Form;

class Bureaucrat
{
    private:
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
                    return "error to high";
                }
        };

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        Bureaucrat(std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &other);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();

        void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif