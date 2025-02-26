#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
    name = "Default";
    this->_hitPoints = FragTrap::_hitPoints;      // 100 from FragTrap
    this->_energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
    this->_attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->_hitPoints = FragTrap::_hitPoints;      // 100 from FragTrap
    this->_energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
    this->_attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
    std::cout << "DiamondTrap parameterized constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->name 
              << ", also known as ClapTrap " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);  // Use ScavTrap's attack function
}
