#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form{
    private:
        const std::string _name;
        bool _issigned;
        const int _signGrade;
        const int _excuteGrade;
    
    public:
        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return "error too low";
            }
        };

        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return "error to high";
            }
        };

        Form();
        Form(std::string name, int signGrade, int excuteGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getFormName() const;
        int getFormSignGrade() const;
        int getFormExcuteGrade() const;
        bool getSignStatus() const;

        void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif