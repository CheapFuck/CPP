#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    
    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Target");
    scav.takeDamage(30);         // Higher HP pool
    scav.beRepaired(20);         // Higher HP pool
    scav.beRepaired(50);         // Higher HP pool
    scav.guardGate();
    
    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Target");
    frag.takeDamage(50);
    frag.beRepaired(30);
    frag.beRepaired(123);
    frag.highFivesGuys();
    
    std::cout << "\n=== Testing Construction/Destruction Order ===" << std::endl;
    {
        std::cout << "\nCreating a FragTrap:" << std::endl;
        FragTrap temp("Temporary");
        std::cout << "\nFragTrap about to be destroyed:" << std::endl;
    }
    return 0;
}