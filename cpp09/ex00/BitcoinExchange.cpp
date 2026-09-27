#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file){
    this->read_db();
    std::ifstream in;
    in.open(file.c_str(),std::ifstream::in);

    std::string line;
    std::string date;
    float price = 0;
    std::getline(in, line, '\n');
    while(std::getline(in, line, '\n')){
        std::string err = "";
        int pos = line.find("|");
        if (pos == std::string::npos)
             err = "Error: bad input => " + line;
        date = line.substr(0, pos);
        if (err != "" && (line.size()-pos)>9)
            err = "Error: too large a number.";
        if (err != "")
        {
            std::istringstream ff(line.substr(pos, line.size()));
            ff >> price;
        }
        if (price < 0)
        {
            err = "Error: not a positive number";
        }
        std::map<std::string, float>::const_iterator it = db.find(date);
        if (it != db.end())
        {
            float total = db[date] * price;
        }
        else
        {
            // not found
        }
    }
}


void BitcoinExchange::read_db(){
    std::ifstream in;
    in.open("data.csv",std::ifstream::in);

    std::string line;
    std::string date;
    float price;
    while(std::getline(in, line, '\n')){
        size_t pos = line.find(",");
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            std::string tmp = line.substr(pos+1, line.size()-1);
            std::istringstream ff(tmp);
            ff >> price;
            db[date] = price;
        }
    }
}