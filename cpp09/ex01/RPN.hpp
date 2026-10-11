#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <list>
#include <climits>

class RPN
{
    private:
        std::stack<long, std::list<long> > st;
        static bool apply(char op, long a, long b, long &res);

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        bool evaluate(const std::string &expr, long &result);
};

#endif