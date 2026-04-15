#include "Form.hpp"

Form::Form() : _name("Default"), _issigned(false), _signGrade(150), _excuteGrade(150)
{
    std::cout << "Default Form created" << std::endl;
}

Form::Form(std::string name, int signGrade, int excuteGrade): _name(name), _signGrade(signGrade),_excuteGrade(excuteGrade) {
    if (signGrade < 1 || excuteGrade < 1 )
        throw GradeTooHighException();
    else if (signGrade > 150 || excuteGrade > 150)
        throw GradeTooLowException();
    std::cout << "creating a form" << std::endl;
    _issigned = false;
}

Form::~Form(){
    std::cout << "form distroyed" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "copying a form " << std::endl;
    this->_issigned = other._issigned;
    return *this;
}

Form::Form(const Form &other):_name(other._name), _signGrade(other._signGrade), _excuteGrade(other._excuteGrade){
    *this = other;
}

std::string Form::getFormName() const{
    return _name;
}

int Form::getFormExcuteGrade() const {
    return _excuteGrade;
}

int Form::getFormSignGrade() const{
    return _signGrade;
}

bool Form::getSignStatus() const {
    return _issigned;
}

std::ostream &operator<<(std::ostream &os, const Form &form){
    os << form.getFormName() << " , signing grade: " << form.getFormSignGrade() << " , excution grade: " << form.getFormExcuteGrade()
       << " , signing: " << form.getSignStatus() << std::endl;
    return os;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->getFormSignGrade()){
        throw GradeTooLowException();
    }
    else
    {
        this->_issigned = true;
    }
}