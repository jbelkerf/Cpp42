#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG \n\t" <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void){
    std::cout << "INFO \n\t" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void){
    std::cout << "WARNING \n\t" << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error(void){
    std::cout << "ERROR \n\t" << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(){
    this->func[0] = &Harl::debug;
    this->func[1] = &Harl::info;
    this->func[2] = &Harl::warning;
    this->func[3] = &Harl::error;
    this->s[0] = "DEBUG";
    this->s[1] = "INFO";
    this->s[2] = "WARNING";
    this->s[3] = "ERROR";

}

void Harl::complain(std::string level){
    int i = 0;
    while (i < 4 && this->s[i] != level)
    {
        i++;
    }
    if (i < 4)
        (this->*func[i])();

}
