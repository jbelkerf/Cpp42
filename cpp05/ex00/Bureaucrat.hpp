#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>

class Bureaucrat
{
    private:
        const std::string tname;
        int tgrade;

    public:
        class GradeTooLowException: public std::exception {
            public:
                virtual const char * what() const throw() ;
        };

        class GradeTooHighException: public std::exception {
            public:
                virtual const char * what() const throw();
        };

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &other);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();
    };

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif