#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyResquestForm: AForm{
    private:
        std::string _target;

    public:
        RobotomyResquestForm(std::string target);
        RobotomyResquestForm(RobotomyResquestForm const & other);
        RobotomyResquestForm &operator=(const RobotomyResquestForm &other);
        ~RobotomyResquestForm();

        void execute(const Bureaucrat &executor) const;
};
#endif