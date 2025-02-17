#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string		Name;
	unsigned int 	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();

	virtual void 	attack(const std::string& target);
	virtual void 	takeDamage(unsigned int amount);
	virtual void 	beRepaired(unsigned int amount);
  	int		get_hit_points();
	int		get_energy_points();
};

#endif
