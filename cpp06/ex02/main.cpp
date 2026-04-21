#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

int main(){
    std::srand((unsigned)time(NULL));
    std::cout << "=== Testing with pointer ===" << std::endl;
    for (int i = 0; i < 6; i++){
        Base* obj = generate();
        std::cout << "generate() returned -> ";
        identify(obj);
        delete obj;
    }

    std::cout << "\n=== Testing with reference ===" << std::endl;
    for (int i = 0; i < 6; i++){
        Base* obj = generate();
        std::cout << "generate() returned -> ";
        identify(*obj);
        delete obj;
    }

    std::cout << "\n=== Direct tests ===" << std::endl;
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    std::cout << "pointer A: "; identify(a);
    std::cout << "pointer B: "; identify(b);
    std::cout << "pointer C: "; identify(c);

    std::cout << "reference A: "; identify(*a);
    std::cout << "reference B: "; identify(*b);
    std::cout << "reference C: "; identify(*c);

    delete a;
    delete b;
    delete c;

    return 0;
}