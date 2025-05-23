#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecuteRequirements(executor);
    
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    outfile << "       _-_              _-_" << std::endl;
    outfile << "    /~~   ~~\\       /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\ /~~         ~~\\" << std::endl;
    outfile << "{               }{               }" << std::endl;
    outfile << " \\  _-     -_  / \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~     ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _ _- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_   _ -  | |   -_" << std::endl;
    outfile << "      // \\\\           // \\\\" << std::endl;
    
    outfile.close();
    std::cout << "Created shrubbery file: " << filename << std::endl;
}