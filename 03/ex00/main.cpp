#include "ClapTrap.hpp"
#include <iostream>

int main() {
    // Test constructors
    ClapTrap defaultBot;                    // Default constructor
    ClapTrap bob("Bob");                    // Parameterized constructor
    ClapTrap bobCopy(bob);                  // Copy constructor
    ClapTrap assigned;                      // Default constructor
    assigned = bob;                         // Assignment operator

    std::cout << "\n--- Testing basic functionality ---\n" << std::endl;
    
    // std::cout << "\n attak is : " << bob.attack << std::endl;
    // Test basic functionality
    bob.attack("Target Dummy");
    bob.takeDamage(5);
    bob.beRepaired(3);
    
    std::cout << "\n--- Testing energy depletion ---\n" << std::endl;
    
    // Test energy point depletion (10 actions)
    for (int i = 0; i < 11; i++) {
        std::cout << "Action " << i + 1 << ": ";
        bob.attack("Target Dummy");
    }
    
    std::cout << "\n--- Testing death ---\n" << std::endl;
    
    // Test death
    ClapTrap kenny("Kenny");
    kenny.takeDamage(15);  // Overkill damage
    kenny.attack("Target Dummy");
    kenny.beRepaired(5);

    return 0;
}