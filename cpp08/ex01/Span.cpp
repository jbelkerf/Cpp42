#include "Span.hpp"

Span::Span(unsigned int N){
    max = N;
    current = 0;
}


Span::Span(const Span &other){
    *this = other;
}

Span &Span::operator=(const Span &other){
    current = other.current;
    max = other.max;
    V = other.V;
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

int Span::longestSpan(void) const{
    if (current < 2)
        throw std::runtime_error("Not enough elements to find span");
    std::vector<int>::const_iterator maxIt = std::max_element(V.begin(), V.end());
    std::vector<int>::const_iterator minIt = std::min_element(V.begin(), V.end());
    return *maxIt - *minIt;
}

int Span::shortestSpan() const{
    if (current < 2)
        throw std::runtime_error("Not enough elements to find span");
    std::vector<int> sorted = V;
    std::sort(sorted.begin(), sorted.end());
    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
    return *std::min_element(diffs.begin() + 1, diffs.end());
}
