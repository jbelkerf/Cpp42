#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137){
    std::cout << "ShrubberyCreationForm has been created" << std::endl;
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137){
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other){
    AForm::operator=(other);
    this->_target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm has ben eliminated" << std::endl;
};

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
    std::ofstream outfile;

    this->isReadyForExecute(executor);
    std::string out = _target + "_shrubbery";
    outfile.open(out.c_str());
    if (!outfile.is_open())
    {
        std::cout << "unable to open " << out << executor.getName()<< std::endl; 
    }
    else
    {
        outfile << "     ccee88oo\n\
  C8O8O8Q8PoOb o8oo\n\
 dOB69QO8PdUOpugoO9bD\n\
CgggbU8OU qOp qOdoUOdcb\n\
    6OuU  /p u gcoUodpP\n\
      \\\\//  /douUP\n\
        \\\\////\n\
         |||/\\\n\
         |||\\/\n\
         |||||\n\
   .....//||||\\....";
        outfile.close();
    }
}
