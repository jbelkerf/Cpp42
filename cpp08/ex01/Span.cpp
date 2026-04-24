#include "Span.hpp"

Span::Span(unsigned int N){
    max = N;
    current = 0;
}
Span::Span(const Span &other){
    *this = other;
}

Span &Span::operator=(const Span &other){
    std::vector<int>::const_iterator it = other.V.begin();

    current = other.current;
    max = other.max;
    while (it != other.V.end())
    {
        this->addNumber(*it);
        it++;
    }
    return *this;
}

Span::~Span(){
    std::cout << "the span eliminated" << std::endl;
}

void Span::addNumber(int number){
    if (current + 1 > max)
        throw std::runtime_error("container reach the max");
    current++;
    V.push_back(number);

}

