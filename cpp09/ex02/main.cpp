#include "PmergeMe.hpp"

int main(int argc, char ** argv){

    std::vector<int> numbers;
    std::deque<int> numbersDq;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        numbers.push_back(number);
        numbersDq.push_back(number);
    }

    std::cout << "Before: ";
    for (size_t k = 0; k < numbers.size(); k++)
        std::cout << numbers[k] << " ";
    std::cout << std::endl;

    PmergeMe pVec(numbers);
    PmergeMe pDq(numbersDq);
}