#include "ClapTrap.hpp"

int main()
{
    // Test constructors
    ClapTrap defaultBot;                    // Default constructor
    ClapTrap bob("Bob");                    // Parameterized constructor
    ClapTrap bobCopy(bob);                  // Copy constructor
    ClapTrap assigned;                      // Default constructor

    assigned = bob;                         // Assignment operator
    std::cout << "\nTESTING\n" << std::endl;
    // Test basic functionality
    bob.attack("Target Dummy");
    bob.takeDamage(5);
    bob.beRepaired(3);
    bob.beRepaired(3);
    // bob.reset();
    // bob._energyPoints = 10;
    std::cout << "\n--- energy depletion ---\n" << std::endl;
    // Test energy point depletion (10 actions)
    for (int i = 0; i < 11; i++)
    {
        std::cout << "Action " << i + 1 << ": ";
        bob.attack("Target Dummy");
    }
    std::cout << "\n--- death ---\n" << std::endl;
    // Test death
    ClapTrap kenny("Kenny");
    kenny.takeDamage(15);  // Overkill damage
    kenny.attack("Target Dummy");
    kenny.beRepaired(5);
    return 0;
}