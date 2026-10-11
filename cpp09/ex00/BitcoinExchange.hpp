#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, double> db;

        static std::string trim(const std::string &s);
        static bool isValidDate(const std::string &date);
        static bool parseValue(const std::string &s, double &out);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        bool loadDb(const std::string &path);
        void processFile(const std::string &path) const;
};

#endif