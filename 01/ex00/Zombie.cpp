#include "Zombie.hpp"

Zombie::Zombie(std::string zombie_name) : name(zombie_name)
{
}

Zombie::~Zombie()
{
    std::cout << name << " is being destroyed." << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
