#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string zombie_name);
    ~Zombie();

    void setName(std::string zombie_name);
    void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif
