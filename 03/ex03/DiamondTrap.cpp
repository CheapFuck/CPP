#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
    _name = "Default";
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _name = name + "_clap_name";
    _hitPoints = FragTrap::_fragHitPoints;      // 100 from FragTrap
    _maxHitPoints = _hitPoints;
    _energyPoints = ScavTrap::_scavEnergyPoints; // 50 from ScavTrap
    _attackDamage = FragTrap::_fragAttackDamage; // 30 from FragTrap
    std::cout << "DiamondTrap parameterized constructor called for " << _name << std::endl;
    // std::cout << "Energy Points: " << this->_energyPoints << std::endl; // Should output the correct value
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
        _name = other._name;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name 
              << ", also known as ClapTrap " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);  // Use ScavTrap's attack function
}


void DiamondTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
	{
        std::cout << "DiamondTrap " << _name << " is already defeated!" << std::endl;
        return ;
    }
    if (amount >= _hitPoints)
	{
         std::cout << "DiamondTrap " << _name << " takes " << _hitPoints << " damage! Remaining HP: 0" << std::endl;
        _hitPoints = 0;
    }
	else
	{
        _hitPoints = _hitPoints - amount;
        std::cout << "DiamondTrap " << _name << " takes " << amount << " damage! Remaining HP: " << _hitPoints << std::endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
	{
        std::cout << "DiamondTrap " << _name << " can't repair - no energy points left!" << std::endl;
        return ;
    }
    if (_hitPoints == 0)
	{
        std::cout << "DiamondTrap " << _name << " can't repair - already defeated!" << std::endl;
        return ;
    }
    if (amount + _hitPoints > _maxHitPoints)
	{
        amount = _maxHitPoints - _hitPoints;
        _hitPoints = _maxHitPoints;
        _energyPoints--;
        std::cout << "DiamondTrap " << _name << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl << "\033[1;31mALERT!!! THIS IS NOT A DRILL!!! MAX HEALTH REACHED!!!\033[0m" << std::endl << "DiamondTrap " << _name << " 100% repaired" << std::endl;
    }
    else
    {
        _hitPoints = _hitPoints + amount;
        _energyPoints--;
        std::cout << "DiamondTrap " << _name << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl;
    }
}

// int DiamondTrap::getEnergyPoints()
// {
//       return _energyPoints;
// }
