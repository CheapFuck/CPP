#include "ScavTrap.hpp"

int main() {
<<<<<<< HEAD
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Target");        // Different message from ClapTrap
    scav.takeDamage(30);         // Higher HP pool
    scav.beRepaired(20);         // Higher HP pool
    scav.guardGate();            // Special ability

    std::cout << "\n=== Testing Construction/Destruction Order ===" << std::endl;
    {
        std::cout << "\nCreating a ScavTrap:" << std::endl;
        ScavTrap temp("Temporary");
        std::cout << "\nScavTrap about to be destroyed:" << std::endl;
    }

    return 0;
}
=======
    ScavTrap scav("Scavvy");
    scav.attack("Enemy");
    scav.guardGate();
    return 0;
}
>>>>>>> 1f377b0e7598102e5ad0de0c1fed8cf1682a1cb7
