#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &o) : st(o.st) {}

RPN &RPN::operator=(const RPN &o)
{
    if (this != &o)
        st = o.st;
    return *this;
}

RPN::~RPN() {}

bool RPN::apply(char op, long a, long b, long &res)
{
    if (op == '+')
    {
        if ((b > 0 && a > LONG_MAX - b) || (b < 0 && a < LONG_MIN - b))
            return false;
        res = a + b;
        return true;
    }
    if (op == '-')
    {
        if ((b < 0 && a > LONG_MAX + b) || (b > 0 && a < LONG_MIN + b))
            return false;
        res = a - b;
        return true;
    }
    if (op == '*')
    {
        if (a != 0 && b != 0)
        {
            if (a > 0 && b > 0 && a > LONG_MAX / b)
                return false;
            if (a > 0 && b < 0 && b < LONG_MIN / a)
                return false;
            if (a < 0 && b > 0 && a < LONG_MIN / b)
                return false;
            if (a < 0 && b < 0 && a < LONG_MAX / b)
                return false;
        }
        res = a * b;
        return true;
    }
    if (op == '/')
    {
        if (b == 0 || (a == LONG_MIN && b == -1))
            return false;
        res = a / b;
        return true;
    }
    return false;
}

bool RPN::evaluate(const std::string &expr, long &result)
{
    st = std::stack<long, std::list<long> >(); // reset

    std::istringstream ss(expr);
    std::string token;
    while (ss >> token)
    {
        if (token.size() != 1)
            return false;
        char c = token[0];
        if (c >= '0' && c <= '9')
            st.push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (st.size() < 2)
                return false;
            long b = st.top();
            st.pop();
            long a = st.top();
            st.pop();
            long res;
            if (!apply(c, a, b, res))
                return false;
            st.push(res);
        }
        else
            return false;
    }
    if (st.size() != 1)
        return false;
    result = st.top();
    return true;
}