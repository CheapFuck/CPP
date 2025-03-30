#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->learned[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.learned[i])
        {
            this->learned[i] = other.learned[i]->clone();
        } else
        {
            this->learned[i] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    // std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->learned[i])
            {
                delete this->learned[i];
                this->learned[i] = nullptr;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.learned[i])
            {
                this->learned[i] = other.learned[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i])
        {
            delete this->learned[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
    {
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i] == nullptr)
        {
            this->learned[i] = m;
            std::cout << "Materia learned in slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << "Cannot learn more materias, all slots are full" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i] && this->learned[i]->getType() == type)
        {
            std::cout << "Creating new materia of type: " << type << std::endl;
            return this->learned[i]->clone();
        }
    }
    
    std::cout << "Unknown materia type: " << type << std::endl;
    return nullptr;
}
