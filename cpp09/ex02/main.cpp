#include "PmergeMe.hpp"

int main(int argc, char ** argv){

    std::vector<int> numbers;
    int count = argc;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        numbers.push_back(number);
    }
    count = argc;
    std::cout << "Before: ";
    for (size_t k = 0; k < numbers.size();k++){
        std::cout << numbers[k] << " ";
    }
    std::cout << std::endl;
    PmergeMe p(numbers);
    // p.print_list();
}