#pragma once
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];
    
public:
    Character();
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();
    
    std::string const & getName() const override;
    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;
};

    