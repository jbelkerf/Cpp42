#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}
void Harl::info(void){
    std::cout << "[ INFO ] "<< std::endl << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}
void Harl::warning(void){
    std::cout << "[ WARNING ]" << std::endl<< "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}
void Harl::error(void){
    std::cout << "[ ERROR ]" << std::endl<< "This is unacceptable! I want to speak to the manager now.\n"  << std::endl;
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
    switch (i)
    {
    case 0:
        this->debug();
    case 1:
        this->info();
    case 2:
        this->warning();
    case 3:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        
    }

}
