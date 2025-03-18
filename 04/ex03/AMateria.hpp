#pragma once
#include <cstring>
#include <iostream>

class AMateria
{
private:
    std::string _type;
protected:
    // std::string type;
    // [...]
public:
    AMateria(std::string const & type);
    AMateria(const AMateria& other);
    // [...]
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};