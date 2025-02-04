#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string		Name;
	unsigned int 	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void 	attack(const std::string& target);
	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);
  	int		get_hit_points();
	int		get_energy_points();
};

#endif
