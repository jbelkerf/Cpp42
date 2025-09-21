#include <iostream>
#include <cctype>

/**
 //? '::' scope resolution operator
 //? '<<' insertion operator
 //? 'endl' is adding '\n' and also flush the stream buffer
 //? '>>' extraction operator
 NAMESPACE is like a liberary that hold a bunch of functions and variables
 the syntax std::cout is like telling the compiler to use the function cout from the namespace std
 we can use //! using namespace std; to include all the std namespace
 if we want just to use only specific functions we can use //! using std::cin; 
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    std::string sentence;
    sentence = argv[1];
    for (int i = 2; i < argc; i++)
        sentence += argv[i];
    for (int i = 0; i < sentence.length(); i++)
        sentence[i] = std::toupper(sentence[i]);
    std::cout << sentence <<std::endl;
    return (0);
}