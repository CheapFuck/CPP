#include "AMateria.hpp"

 AMateria::AMateria(std::string const & type)
 {
    _type(type);
 }


//copy cuntstructor
AMateria::AMateria(const AMateria& other)
{
    this->_type = other._type;  // Copy the type from the other object
}
