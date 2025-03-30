class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}

    protected:
        IMateriaSource() = default;
        IMateriaSource(const IMateriaSource&) = delete;
        IMateriaSource& operator=(const IMateriaSource&) = delete;
    
    public:
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
    };