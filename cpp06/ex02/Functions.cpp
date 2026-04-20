#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    static int i = 0;

    if (i  == 0)
        return new A();
    else if (i == 1)
        return new B();
    else 
    return new C();
    i = (i + 5) % 3 ;
}


void identify(Base* p);
void identify(Base& p);
