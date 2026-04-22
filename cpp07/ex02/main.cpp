#include "Array.hpp"
#include <iostream>

int main(){
    // Test default constructor
    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;

    // Test n constructor
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;

    // Test [] access
    std::cout << "arr[2] = " << arr[2] << std::endl;

    // Test deep copy
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "original arr[0] = " << arr[0] << std::endl;
    std::cout << "copy arr[0]     = " << copy[0] << std::endl;

    // Test assignment
    Array<int> assigned;
    assigned = arr;
    assigned[1] = 888;
    std::cout << "original arr[1]  = " << arr[1] << std::endl;
    std::cout << "assigned arr[1]  = " << assigned[1] << std::endl;

    // Test out of bounds exception
    try {
        std::cout << arr[99] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: out of bounds" << std::endl;
    }

    // Test with strings
    Array<std::string> strArr(3);
    strArr[0] = "hello";
    strArr[1] = "42";
    strArr[2] = "world";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << std::endl;

    return 0;
}