#include "Character.hpp"
#include <iostream>

Character::Character() : name("") {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = nullptr;
    }
}

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character name constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = nullptr;
    }
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    // Deep copy of the inventory
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = nullptr;
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        
        // Clear current inventory
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i]) {
                delete this->inventory[i];
                this->inventory[i] = nullptr;
            }
        }
        
        // Deep copy other's inventory
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
        }
    }
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == nullptr) {
            this->inventory[i] = m;
            std::cout << "Materia equipped in slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << "Inventory is full, cannot equip more materias" << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->inventory[idx]) {
        std::cout << "Materia unequipped from slot " << idx << std::endl;
        this->inventory[idx] = nullptr;
    } else {
        std::cout << "No materia to unequip at slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->inventory[idx]) {
        this->inventory[idx]->use(target);
    } else {
        std::cout << "No materia to use at slot " << idx << std::endl;
    }
}