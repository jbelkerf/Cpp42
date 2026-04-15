#include "AForm.hpp"

AForm::AForm() : _name("Default"), _issigned(false), _signGrade(150), _excuteGrade(150)
{
    std::cout << "Default AForm created" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int excuteGrade): _name(name), _signGrade(signGrade),_excuteGrade(excuteGrade) {
    if (signGrade < 1 || excuteGrade < 1 )
        throw GradeTooHighException();
    else if (signGrade > 150 || excuteGrade > 150)
        throw GradeTooLowException();
    std::cout << "creating a Aform" << std::endl;
    _issigned = false;
}

AForm::~AForm(){
    std::cout << "Aform distroyed" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "copying a Aform " << std::endl;
    this->_issigned = other._issigned;
    return *this;
}

AForm::AForm(const AForm &other):_name(other._name), _signGrade(other._signGrade), _excuteGrade(other._excuteGrade){
    *this = other;
}

std::string AForm::getFormName() const{
    return _name;
}

int AForm::getFormExcuteGrade() const {
    return _excuteGrade;
}

int AForm::getFormSignGrade() const{
    return _signGrade;
}

bool AForm::getSignStatus() const {
    return _issigned;
}

std::ostream &operator<<(std::ostream &os, const AForm &form){
    os << form.getFormName() << " , signing grade: " << form.getFormSignGrade() << " , excution grade: " << form.getFormExcuteGrade()
       << " , signing: " << form.getSignStatus() << std::endl;
    return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->getFormSignGrade()){
        throw GradeTooLowException();
    }
    else
    {
        this->_issigned = true;
    }
}

bool AForm::isReadyForExecute(const Bureaucrat &executor) const{

    if (!this->getSignStatus())
        throw NotSigned();
    if (this->getFormExcuteGrade() > executor.getGrade())
    {
        throw NotPermited();
    }
}