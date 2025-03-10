#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _maxHitPoints = _hitPoints;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _maxHitPoints = _hitPoints;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack - no energy points left!" << std::endl;
        return ;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack - no hit points left!" << std::endl;
        return ;
    }
    
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
	{
        std::cout << "ScavTrap " << _name << " is already defeated!" << std::endl;
        return ;
    }
    if (amount >= _hitPoints)
	{
         std::cout << "ScavTrap " << _name << " takes " << _hitPoints << " damage! Remaining HP: 0" << std::endl;
        _hitPoints = 0;
    }
	else
	{
        _hitPoints = _hitPoints - amount;
        std::cout << "ScavTrap " << _name << " takes " << amount << " damage! Remaining HP: " << _hitPoints << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
	{
        std::cout << "ScavTrap " << _name << " can't repair - no energy points left!" << std::endl;
        return ;
    }
    if (_hitPoints == 0)
	{
        std::cout << "ScavTrap " << _name << " can't repair - already defeated!" << std::endl;
        return ;
    }
    if (amount + _hitPoints > _maxHitPoints)
	{
        amount = _maxHitPoints - _hitPoints;
        _hitPoints = _maxHitPoints;
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl << "\033[1;31mALERT!!! THIS IS NOT A DRILL!!! MAX HEALTH REACHED!!!\033[0m" << std::endl << "ScavTrap " << _name << " 100% repaired" << std::endl;
    }
    else
    {
        _hitPoints = _hitPoints + amount;
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl;
    }
}

// void ScavTrap::reset(void)
// {
//     _energyPoints = 10;
// 	_hitPoints = 10;
//     _attackDamage = 0;
//     std::cout << "ScavTrap " << _name << " reset " << std::endl;
// }
