// #include <iostream>
// #include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
// #include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main() {
    // Test from the subject
    std::cout << "=== Basic Test from Subject ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    // Additional tests
    // std::cout << "\n=== Additional Tests ===" << std::endl;
    
    // // Test Character deep copy
    // std::cout << "\n-- Testing Character Deep Copy --" << std::endl;
    // Character alice("Alice");
    // alice.equip(new Ice());
    // alice.equip(new Cure());
    
    // Character aliceCopy = alice; // Using copy constructor
    
    // std::cout << "Original Alice using materials:" << std::endl;
    // alice.use(0, alice); // Alice uses Ice on herself
    // alice.use(1, alice); // Alice uses Cure on herself
    
    // std::cout << "Copied Alice using materials:" << std::endl;
    // aliceCopy.use(0, aliceCopy); // AliceCopy uses Ice on herself
    // aliceCopy.use(1, aliceCopy); // AliceCopy uses Cure on herself
    
    // // Test unequip
    // std::cout << "\n-- Testing Unequip --" << std::endl;
    // Character charlie("Charlie");
    // AMateria* ice = new Ice();
    // charlie.equip(ice);
    // charlie.use(0, alice); // Use before unequipping
    
    // charlie.unequip(0);
    // charlie.use(0, alice); // Try to use after unequipping - should fail
    
    // // Don't forget to delete unequipped materia to avoid leaks in real code
    // delete ice;
    
    // // Test full inventory
    // std::cout << "\n-- Testing Full Inventory --" << std::endl;
    // Character dave("Dave");
    // dave.equip(new Ice());
    // dave.equip(new Cure());
    // dave.equip(new Ice());
    // dave.equip(new Cure());
    // dave.equip(new Ice()); // Should fail - inventory full
    
    // // Test MateriaSource full
    // std::cout << "\n-- Testing Full MateriaSource --" << std::endl;
    // MateriaSource source;
    // source.learnMateria(new Ice());
    // source.learnMateria(new Cure());
    // source.learnMateria(new Ice());
    // source.learnMateria(new Cure());
    // source.learnMateria(new Ice()); // Should fail - already learned 4 materias
    
    // // Test unknown materia type
    // std::cout << "\n-- Testing Unknown Materia Type --" << std::endl;
    // tmp = source.createMateria("fire"); // Should return nullptr
    // if (!tmp) {
    //     std::cout << "Successfully returned nullptr for unknown materia type" << std::endl;
    // } else {
    //     delete tmp;
    // }
    
    return 0;
}