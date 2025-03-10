#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap() override;

    void attack(const std::string& target) override;
    void takeDamage(unsigned int amount) override;
    void beRepaired(unsigned int amount) override;
    void highFivesGuys(void);

protected:
	static unsigned int const _fragHitPoints = 100;
	static unsigned int const _fragEnergyPoints = 100;
	static unsigned int const _fragAttackDamage = 30;
};
