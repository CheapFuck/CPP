#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    
    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Target");
    scav.guardGate();
    
    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Target");
    frag.highFivesGuys();
    
    std::cout << "\n=== Testing DiamondTrap ===" << std::endl;
    DiamondTrap diamond("Diamond");
    
    // Test attributes from different parents
    diamond.attack("Target");        // Should use ScavTrap's attack
    diamond.guardGate();             // From ScavTrap
    diamond.highFivesGuys();         // From FragTrap
    diamond.whoAmI();                // DiamondTrap's special function
    
    // Test attributes
    diamond.takeDamage(30);          // HP from FragTrap (100)
  
    // Test energy consumption (multiple attacks to see energy depleting)
    std::cout << "\nTesting energy consumption (from ScavTrap: 50 points)" << std::endl;
    for (int i = 0; i < 60; i++)
    {
        diamond.attack("Target");
        // std::cout << "energy points: " << diamond.getEnergyPoints()<< std::endl;
    }
    std::cout << "\n=== Testing Construction/Destruction Order ===" << std::endl;
    {
        std::cout << "\nCreating a DiamondTrap:" << std::endl;
        DiamondTrap temp("Temporary");
        std::cout << "\nDiamondTrap about to be destroyed:" << std::endl;
    }
    return 0;
}
