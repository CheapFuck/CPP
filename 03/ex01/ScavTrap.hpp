#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap() override;

    void attack(const std::string& target) override;  // Override attack
    void guardGate();

    void takeDamage(unsigned int amount) override;
    void beRepaired(unsigned int amount) override;

    // void reset(void);
};
