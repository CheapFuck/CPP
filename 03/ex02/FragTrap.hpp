#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap() override;

    void attack(const std::string& target) override;  // Override attack
    void takeDamage(unsigned int amount) override;
    void beRepaired(unsigned int amount) override;

    void highFivesGuys(void);
};
