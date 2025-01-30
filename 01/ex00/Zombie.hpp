#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie(std::string zombie_name);
    ~Zombie();
    void announce();
};

#endif
