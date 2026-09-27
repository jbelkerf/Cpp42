#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

class BitcoinExchange{
    private:
        std::map<std::string, float> db;
    public:
        BitcoinExchange(std::string file);
        void read_db();
        float get_loweer_date(std::string date);
        
};
#endif

//2147483647