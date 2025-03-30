#include "Character.hpp"

Character::Character() : name(""), inventory{nullptr, nullptr, nullptr, nullptr}
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const & name) : name(name), inventory{nullptr, nullptr, nullptr, nullptr}
{
    std::cout << "Character name constructor called" << std::endl;
}

Character::Character(const Character& other) : name(other.name)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = (other.inventory[i]) ? other.inventory[i]->clone() : nullptr;
    }
}
Character& Character::operator=(const Character& other)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
    
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = nullptr;
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
        }
    }
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == nullptr)
        {
            this->inventory[i] = m;
            std::cout << "Materia equipped in slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << "Inventory is full, cannot equip more materias" << std::endl;
}
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        std::cout << "Materia unequipped and deleted from slot " << idx << std::endl;
        delete inventory[idx];  // Free memory
        inventory[idx] = nullptr;
    } else
    {
        std::cout << "No materia to unequip at slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);
    }
    else
    {
        std::cout << "No materia to use at slot " << idx << std::endl;
    }
}
