#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

class Span{
    private:
        unsigned int max;
        unsigned int current;
        std::vector<int> V;
        Span();


    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            ptrdiff_t dist = std::distance(begin, end);
            if (dist < 0 || (unsigned int)dist + current > max)
                throw std::runtime_error("Not enough space");
            V.insert(V.end(), begin, end);
            current += dist;
        }
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif