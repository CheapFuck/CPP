#include "ClapTrap.hpp"

// constructors
ClapTrap::ClapTrap() : Name("Default")
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : Name(name)
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
	if (this->hit_points == 0)
		std::cout << this->Name << " is dead and cannot attack someone." << std::endl;
	else if (this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "Not enough energy points for attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0 && amount != 0)
		std::cout << this->Name << " has zero hit points, cannot go below zero" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->Name << " took " << amount << " points of damage!" << std::endl;
		if (amount > this->hit_points)
			this->hit_points = 0;
		else
			this->hit_points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
		std::cout << this->Name << " is already dead and cannot be repaired." << std::endl;
	else if (this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->Name << " got " << amount << " points of hit points!" << std::endl;
		this->hit_points += amount;
		this->energy_points -= 1;
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