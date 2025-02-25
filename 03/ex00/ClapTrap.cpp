#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : 
    _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : 
    _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap parameterized constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

// Member functions
void ClapTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't attack - no energy or hit points left!" << std::endl;
        return;
    }
    std::cout << "\n attak is : " << _attackDamage << std::endl;

    
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already defeated!" << std::endl;
        return;
    }
    
    if (amount >= _hitPoints) {
        _hitPoints = 0;
    } else {
        _hitPoints -= amount;
    }
    
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage! Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't repair - no energy points left!" << std::endl;
        return;
    }
    
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't repair - already defeated!" << std::endl;
        return;
    }

    _hitPoints += amount;
    _energyPoints--;
    
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl;
}