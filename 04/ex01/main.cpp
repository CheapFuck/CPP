#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* i = new Dog();
//     const Animal* j = new Cat();
    
//     i->makeSound();
//     j->makeSound();

//     delete i;
//     delete j;

//     Animal* animals[2];
//     animals[0] = new Dog();
//     animals[1] = new Cat();

//     for (int i = 0; i < 2; ++i)
//     {
//         animals[i]->makeSound();
//     }
//     for (int i = 0; i < 2; ++i)
//     {
//         delete animals[i];
//     }
//     Dog dog1;
//     dog1.makeSound();
//     Dog dog2 = dog1;
//     dog2.makeSound();

//     Cat cat1;
//     cat1.makeSound();
//     Cat cat2;
//     cat2 = cat1;
//     cat2.makeSound();

//     return 0;
// }

int main() {
    // Test 1: Create Dog and Cat objects and delete them properly
    const Animal* i = new Dog();
    const Animal* j = new Cat();
    
    i->makeSound();  // Expected: Woof!
    j->makeSound();  // Expected: Meow!

    // Deleting objects
    delete i; // Calls Dog destructor and Animal destructor
    delete j; // Calls Cat destructor and Animal destructor

    // Test 2: Create an array of Animals using polymorphism
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; ++i) {
        animals[i]->makeSound();
    }

    // Deleting objects
    for (int i = 0; i < 2; ++i) {
        delete animals[i];  // Will call the destructors in the right order
    }

    // Test 3: Copy constructor and deep copy check for Dog
    Dog dog1;
    dog1.makeSound(); // Woof!
    
    Dog dog2 = dog1; // Using the copy constructor
    dog2.makeSound(); // Woof!

    // Test 4: Copy assignment and deep copy check for Cat
    Cat cat1;
    cat1.makeSound(); // Meow!

    Cat cat2;
    cat2 = cat1; // Using the copy assignment operator
    cat2.makeSound(); // Meow!

    // Check if deep copy occurred by comparing memory addresses of `type`
    if (dog1.getType() != dog2.getType())
    {
        std::cout << "Dog deep copy: Passed (different memory for type)" << std::endl;
    } else
    {
        std::cout << "Dog deep copy: Failed (same memory for type)" << std::endl;
    }

    if (cat1.getType() != cat2.getType())
    {
        std::cout << "Cat deep copy: Passed (different memory for type)" << std::endl;
    } else
    {
        std::cout << "Cat deep copy: Failed (same memory for type)" << std::endl;
    }

    return 0;
}