#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG" << " level: Debug messages contain contextual information. They are mostly used for problem diagnosis." << std::endl;
}
void Harl::info(void){
    std::cout << "INFO" << "level: These messages contain extensive information. They are helpful for tracing program execution in a production environment. " << std::endl;
}
void Harl::warning(void){
    std::cout << "WARNING" << std::endl;
}
void Harl::error(void){
    std::cout << "ERROR"  << std::endl;
}

Harl::Harl(){
    this->func[0] = &Harl::debug;
    this->func[1] = &Harl::info;
    this->func[2] = &Harl::warning;
    this->func[3] = &Harl::error;
    this->s[0] = "debug";
    this->s[1] = "info";
    this->s[2] = "warning";
    this->s[3] = "error";

}

void Harl::complain(std::string level){
    int i = 0;
    while (this->s[i] != level)
    {
        i++;
    }
    if (i < 4)
        (this->*func[i])();

}
