#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
    std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.sources[i])
            sources[i] = other.sources[i]->clone();
        else
            sources[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource assignment operator called." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (sources[i])
            {
                delete sources[i];
                sources[i] = NULL;
            }
            if (other.sources[i])
                sources[i] = other.sources[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (sources[i])
        {
            delete sources[i];
            sources[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] == NULL)
        {
            sources[i] = m;
            std::cout << "MateriaSource learned materia of type: " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource cannot learn more materia, inventory full." << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] && sources[i]->getType() == type)
        {
            std::cout << "MateriaSource created materia of type: " << type << std::endl;
            return sources[i]->clone();
        }
    }
    std::cout << "MateriaSource cannot create materia of type: " << type << ", not learned." << std::endl;
    return NULL;
}
