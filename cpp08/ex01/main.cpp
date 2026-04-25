#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // Test with 10000 numbers
    Span bigSpan(10000);
    std::vector<int> big;
    for (int i = 0; i < 10000; i++)
        big.push_back(std::rand());
    bigSpan.addRange(big.begin(), big.end());
    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
    return 0;
}