#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &o) : db(o.db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &o)
{
    if (this != &o)
        db = o.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &s)
{
    size_t first = s.find_first_not_of(" \t\r");
    if (first == std::string::npos)
        return "";
    size_t last = s.find_last_not_of(" \t\r");
    return s.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && leap)
        maxDay = 29;
    return day <= maxDay;
}

bool BitcoinExchange::parseValue(const std::string &s, double &out)
{
    if (s.empty())
        return false;
    std::istringstream ss(s);
    char leftover;
    if (!(ss >> out) || (ss >> leftover))
        return false;
    return true;
}

bool BitcoinExchange::loadDb(const std::string &path)
{
    std::ifstream in(path.c_str());
    if (!in.is_open())
    {
        std::cerr << "Error: could not open " << path << "." << std::endl;
        return false;
    }
    std::string line;
    std::getline(in, line); // header
    while (std::getline(in, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        double rate;
        if (isValidDate(date) && parseValue(line.substr(pos + 1), rate))
            db[date] = rate;
    }
    if (db.empty())
    {
        std::cerr << "Error: empty database." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::processFile(const std::string &path) const
{
    std::ifstream in(path.c_str());
    if (!in.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::cout << std::setprecision(10);
    std::string line;
    bool first = true;
    while (std::getline(in, line))
    {
        if (first)
        {
            first = false;
            if (trim(line) == "date | value")
                continue;
        }

        size_t pos = line.find('|');
        std::string date = trim(pos == std::string::npos ? line : line.substr(0, pos));
        if (pos == std::string::npos || !isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        double val;
        if (!parseValue(trim(line.substr(pos + 1)), val))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (val < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::const_iterator it = db.upper_bound(date);
        if (it == db.begin())
        {
            std::cout << "Error: no earlier date in database => " << date << std::endl;
            continue;
        }
        --it;
        std::cout << date << " => " << val << " = " << it->second * val << std::endl;
    }
}