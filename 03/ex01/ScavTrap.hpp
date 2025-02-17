#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
// private:
//     std::string		Name;
// 	unsigned int 	hit_points;
// 	unsigned int	energy_points;
// 	unsigned int	attack_damage;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap() override;

	// void 	attack(const std::string& target);
	// void 	takeDamage(unsigned int amount);
	// void 	beRepaired(unsigned int amount);
  	// int		get_hit_points();
	// int		get_energy_points();
	void guardGate();
};

#endif
