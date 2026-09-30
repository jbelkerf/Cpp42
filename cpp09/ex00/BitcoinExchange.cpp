#include "BitcoinExchange.hpp"

std::string BitcoinExchange::trimm(std::string d){
    int first = -1;
    int last = 0;
    for (size_t i =0; i < d.size();i++)
    {
        if (first == -1 && (d[i] != ' ' && d[i] != '\t'))
            first = i;
        if (first != -1 && (d[i] == '|' || d[i] == ' ' || d[i] == '\t' || d[i] == 0))
        {
            last = i;
            return d.substr(first, last);
        }
    }
    return d;
}


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
        size_t pos = line.find("|");
            float total = 0;
        date = trimm(line);
        if (pos == std::string::npos){

            err = "Error: bad input => " + line;
        }
        else
        {
            // 2147483647
            if (err.empty() && ((trimm(line.substr(pos+1, line.size()-1)))>"2147483647"|| (trimm(line.substr(pos+1, line.size()-1)).size())>10 ))
                err = "Error: too large a number.";
            if (err.empty())
            {
                std::istringstream ff(trimm(line.substr(pos+1, line.size())));
                ff >> price;
            }
            if (price < 0 && err.empty())
            {
                err = "Error: not a positive number";
            }
            std::map<std::string, float>::const_iterator it = db.find(date);
            if (it != db.end())
            {
                total = db[date] * price;
            }
            else
            {
                // std::cout << "date :: " << date << std::endl;
                for (std::map<std::string, float>::const_iterator it = db.begin(); it != db.end(); ++it)
                {
                    if (it->first < date){
                        total = it->second *price;
                    }
                    else{
                        // it--;
                        // std::cout << "updated date : " << it->first << std::endl;
                        // std::cout << "updated price : " << price << std::endl;
                        break;
                    }
                }
            }
        }
        if (err.empty())
        {
            std::cout << date << " => " << price << " = " << total << std::endl;
        }
        else
            std::cout <<err << std::endl;
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