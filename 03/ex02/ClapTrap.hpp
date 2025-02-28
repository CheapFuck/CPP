#pragma once
// #ifndef CLAPTRAP_HPP
// #define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap();  // Virtual destructor

    virtual void attack(const std::string& target);  // Virtual attack function
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
};

// #endif