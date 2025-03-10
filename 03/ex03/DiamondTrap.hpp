#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap() override;

    void attack(const std::string& target) override;
    void takeDamage(unsigned int amount) override;
    void beRepaired(unsigned int amount) override;

    void whoAmI();
    // int getEnergyPoints();
};
