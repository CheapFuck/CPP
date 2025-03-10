#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap() override;

    void attack(const std::string& target) override;
    void takeDamage(unsigned int amount) override;
    void beRepaired(unsigned int amount) override;
    void guardGate();

protected:
	static unsigned int const _scavHitPoints = 100;
	static unsigned int const _scavEnergyPoints = 50;
	static unsigned int const _scavAttackDamage = 20;
};
