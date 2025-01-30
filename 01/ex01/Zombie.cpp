#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string zombie_name) : name(zombie_name) {}

Zombie::~Zombie()
{
    std::cout << name << " is being destroyed." << std::endl;
}

void Zombie::setName(std::string zombie_name)
{
    name = zombie_name;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
