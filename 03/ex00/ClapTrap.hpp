#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
private:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _maxHitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

public:
    // Orthodox Canonical Form requirements
    ClapTrap();                                 // Default constructor
    ClapTrap(const std::string& name);          // Parameterized constructor
    ClapTrap(const ClapTrap& other);            // Copy constructor
    ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
    ~ClapTrap();                                // Destructor

    // Required member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // random member functions
    void reset(void);
};
