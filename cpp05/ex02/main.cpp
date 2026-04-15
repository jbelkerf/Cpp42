#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {

    ShrubberyCreationForm *tree = new ShrubberyCreationForm("tree");
    Bureaucrat *a = new Bureaucrat("ja", 1);
    tree->execute(*a);
}