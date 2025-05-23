#pragma once
#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
protected:
    std::string type;
    
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();
    
    std::string const & getType() const;
    virtual std::string const & getName() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};