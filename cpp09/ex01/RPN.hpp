#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <string>
#include <stack>

class RPN{
    private:
        std::stack<int > st;
    public:
        RPN(std::string s);
        // int get_elment();
};

#endif