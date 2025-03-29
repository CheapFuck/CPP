#pragma once
#include "ICharacter.hpp" // Vereist omdat we erven van ICharacter
#include <cstring>
#include <iostream>

class ICharacter; // Forward declaration

class AMateria {
protected:
    std::string type;
    
public:
    AMateria();                                // Default constructor
    AMateria(std::string const & type);        // Parameterized constructor
    AMateria(const AMateria& other);           // Copy constructor
    AMateria& operator=(const AMateria& other); // Copy assignment operator
    virtual ~AMateria();                       // Virtual destructor
    
    std::string const & getType() const;
    virtual std::string const & getName() const;

    virtual AMateria* clone() const = 0;       // Pure virtual
    virtual void use(ICharacter& target);
};