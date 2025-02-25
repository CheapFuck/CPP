#include "ClapTrap.hpp"

<<<<<<< HEAD
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
=======
// constructors
ClapTrap::ClapTrap() : Name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : Name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) :  Name(other.Name), hit_points(other.hit_points),
	energy_points(other.energy_points), attack_damage(other.attack_damage)
{
	std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment constructor called\n";
	this->Name = other.Name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor called\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_points < 1)
		std::cout << this->Name << " is dead and cannot attack someone." << std::endl;
	else if (this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else
		std::cout << "Not enough energy points for attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points < 1 && amount > 0)
		std::cout << this->Name << " has zero hit points, cannot go below zero" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->Name << " took " << amount << " points of damage!" << std::endl;
		if (amount > this->hit_points)
			this->hit_points = 0;
		else
			this->hit_points = this->hit_points - amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points < 1)
		std::cout << this->Name << " is already dead and cannot be repaired." << std::endl;
	else if (this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->Name << " got " << amount << " points of hit points!" << std::endl;
		this->hit_points += amount;
		this->energy_points--;
	}
	else
		std::cout << "Not enough energy points for being repaired" << std::endl;
}

int ClapTrap::get_hit_points()
{
	return (this->hit_points);
}

int ClapTrap::get_energy_points()
{
	return (this->energy_points);
}
>>>>>>> 1f377b0e7598102e5ad0de0c1fed8cf1682a1cb7
