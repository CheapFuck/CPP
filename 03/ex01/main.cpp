#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.beRepaired(33);

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Target");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.beRepaired(50);
    scav.guardGate();

    std::cout << "\n=== Testing Construction/Destruction Order ===" << std::endl;
    {
        std::cout << "\nCreating a ScavTrap:" << std::endl;
        ScavTrap temp("Temporary");
        std::cout << "\nScavTrap about to be destroyed:" << std::endl;
    }
    return 0;
}
