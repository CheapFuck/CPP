#include "ScavTrap.hpp"
<<<<<<< HEAD

ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " can't attack - no energy or hit points left!" << std::endl;
        return;
    }
    
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
=======
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
>>>>>>> 1f377b0e7598102e5ad0de0c1fed8cf1682a1cb7
