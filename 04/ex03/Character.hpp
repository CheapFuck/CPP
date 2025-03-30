#pragma once
#include "ICharacter.hpp" // Include the full definition
#include "AMateria.hpp"   // Include for AMateria*

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
    
public:
    Character();
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();
    
    std::string const & getName() const override;
    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;
};

    