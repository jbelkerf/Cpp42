# ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        void setfname(std::string name);
        void setlname(std::string name);
        void setnname(std::string name);
        void setpnumber(std::string number);
        void setdsecret(std::string secret);
        
        std::string getfname(void);
        std::string getlname(void);
        std::string getnname(void);
};

# endif