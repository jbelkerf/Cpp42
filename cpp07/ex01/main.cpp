#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T &x) {
    std::cout << x << std::endl;
}

template <typename T>
void printConst(const T &x) {
    std::cout << x << std::endl;
}

template <typename T>
void doubleIt(T &x) {
    x *= 2;
}

int main() {
    // Test with int array
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "--- int array ---" << std::endl;
    iter(arr, 5, print<int>);

    // Test doubling
    iter(arr, 5, doubleIt<int>);
    std::cout << "--- after doubling ---" << std::endl;
    iter(arr, 5, print<int>);

    // Test with string array
    std::string strs[] = {"hello", "world", "42"};
    std::cout << "--- string array ---" << std::endl;
    iter(strs, 3, print<std::string>);

    // Test with const array
    const int constArr[] = {10, 20, 30};
    std::cout << "--- const int array ---" << std::endl;
    iter(constArr, 3, printConst<int>);

    return 0;
}