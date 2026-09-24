#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file){
    std::ifstream in;
    in.open(file.c_str(),std::ifstream::in);

    std::string line;
    while(std::getline(in, line, '\n')){
        std::cout << line << std::endl;
    }
}