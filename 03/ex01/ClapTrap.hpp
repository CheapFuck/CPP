#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

<<<<<<< HEAD
#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap();

    virtual void attack(const std::string& target);  // Added virtual keyword
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
=======
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
>>>>>>> 1f377b0e7598102e5ad0de0c1fed8cf1682a1cb7
