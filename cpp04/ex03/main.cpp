#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
int main()
{
    std::cout << "-------creating source and learning materias-------" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());

    std::cout << "\n\n-------creating character and equipping materias-------" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));


    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);


    std::cout << "\n\n---------deleting everything-------" << std::endl;
    delete bob;
    delete me;
    delete src;

    
    
    return 0;
}