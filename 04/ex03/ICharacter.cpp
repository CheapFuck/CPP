#include <string>

class ICharacter {
public:
    virtual ~ICharacter() {}  // Virtual destructor to ensure proper cleanup
    virtual std::string const & getName() const = 0;
};