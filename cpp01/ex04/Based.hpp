#ifndef BASED_HPP
#define BASED_HPP
#include <iostream>
#include <fstream>

class Based
{
    private:
        std::ifstream infile;
        std::ofstream outfile;
        std::string s1;
        std::string s2;
        int err;

    public:
        Based(std::string in, std::string out, std::string _s1, std::string _s2);
        ~Based();
        void execute(void);
};
#endif