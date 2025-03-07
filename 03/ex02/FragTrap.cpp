#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _maxHitPoints = _hitPoints;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _maxHitPoints = _hitPoints;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap parameterized constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " can't attack - no energy points left!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "FragTrap " << _name << " can't attack - no hit points left!" << std::endl;
        return;
    }
    
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
	{
        std::cout << "FragTrap " << _name << " is already defeated!" << std::endl;
        return;
    }
    if (amount >= _hitPoints)
	{
         std::cout << "FragTrap " << _name << " takes " << _hitPoints << " damage! Remaining HP: 0" << std::endl;
        _hitPoints = 0;
    }
	else
	{
        _hitPoints = _hitPoints - amount;
        std::cout << "FragTrap " << _name << " takes " << amount << " damage! Remaining HP: " << _hitPoints << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
	{
        std::cout << "FragTrap " << _name << " can't repair - no energy points left!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
	{
        std::cout << "FragTrap " << _name << " can't repair - already defeated!" << std::endl;
        return;
    }
    if (amount + _hitPoints > _maxHitPoints)
	{
        amount = _maxHitPoints - _hitPoints;
        _hitPoints = _maxHitPoints;
        _energyPoints--;
        std::cout << "FragTrap " << _name << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl << "\033[1;31mALERT!!! THIS IS NOT A DRILL!!! MAX HEALTH REACHED!!!\033[0m" << std::endl << "FragTrap " << _name << " 100% repaired" << std::endl;
    }
    else
    {
        _hitPoints = _hitPoints + amount;
        _energyPoints--;
        std::cout << "FragTrap " << _name << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl;
    }
}

// void ScavTrap::reset(void)
// {
//     _energyPoints = 10;
// 	_hitPoints = 10;
//     _attackDamage = 0;
//     std::cout << "ScavTrap " << _name << " reset " << std::endl;
// }
