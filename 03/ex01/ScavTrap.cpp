#include "ScavTrap.hpp"
// constructors
  ScavTrap(std::string name) : ClapTrap(name) {
        hitPoints = 150;  // Specific to ScavTrap, modifying base class's member variables
        energyPoints = 50; // Specific to ScavTrap
        attackDamage = 20; // Specific to ScavTrap
        std::cout << "ScavTrap constructor called for " << name << std::endl;
    }

ClapTrap::ClapTrap(std::string name) : Name(name), hit_points(10), energy_points(10), attack_damage(0)
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





class ScavTrap : public ClapTrap {
public:
    // Constructor for ScavTrap
    ScavTrap(std::string name) : ClapTrap(name) {
        hitPoints = 150;  // Specific to ScavTrap, modifying base class's member variables
        energyPoints = 50; // Specific to ScavTrap
        attackDamage = 20; // Specific to ScavTrap
        std::cout << "ScavTrap constructor called for " << name << std::endl;
    }

    // Destructor for ScavTrap
    ~ScavTrap() override {
        std::cout << "ScavTrap destructor called for " << name << std::endl;
    }

    // ScavTrap-specific method
    void guardGate() {
        std::cout << name << " is now guarding the gate!" << std::endl;
    }
};