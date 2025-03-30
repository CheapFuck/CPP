#include "AMateria.hpp"
#include "IMateriasource.hpp"


class MateriaSource : public IMateriaSource
{
private:
    AMateria* learned[4];
    
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();
    
    void learnMateria(AMateria* m) override;
    AMateria* createMateria(std::string const & type) override;
};