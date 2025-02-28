// #ifndef CLAPTRAP_HPP
// #define CLAPTRAP_HPP
#pragma once

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
    virtual ~ClapTrap();

    virtual void attack(const std::string& target);  // Added virtual keyword
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

// #endif
