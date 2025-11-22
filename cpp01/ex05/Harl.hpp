#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
    private:
        void (Harl::*func[4])(void);
        std::string s[4];
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    
    public:
        Harl(void);
        void complain(std::string level);
};
#endif