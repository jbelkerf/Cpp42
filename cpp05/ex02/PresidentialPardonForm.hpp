#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonFrom : public AForm{
    private:
        std::string _target;
    
    public:
        PresidentialPardonFrom(std::string target);
        PresidentialPardonFrom(const PresidentialPardonFrom &other);
        PresidentialPardonFrom &operator=(const PresidentialPardonFrom &other);
        ~PresidentialPardonFrom();

        void execute(Bureaucrat const &executor) const;
};

#endif