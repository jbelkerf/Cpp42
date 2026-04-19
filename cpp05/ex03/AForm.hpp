#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class AForm{
    private:
        const std::string _name;
        bool _issigned;
        const int _signGrade;
        const int _excuteGrade;
    
    public:
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NotPermited : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class AlreadySignedException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        AForm();
        AForm(std::string name, int signGrade, int excuteGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getFormName() const;
        int getFormSignGrade() const;
        int getFormExcuteGrade() const;
        bool getSignStatus() const;

        void beSigned(const Bureaucrat &bureaucrat);

        virtual void execute(Bureaucrat const &executor) const = 0;

        bool isReadyForExecute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif