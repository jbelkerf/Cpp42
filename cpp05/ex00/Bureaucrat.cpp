#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): tname(name)
{
    if (grade >= 1 && grade <= 150)
    {
        throw bureauException();
    }
    else
        tgrade = grade;
}