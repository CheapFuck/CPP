#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors & Destructors
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// Copy Assignment Operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
        // Note: gradeToSign and gradeToExecute are const, so they cannot be reassigned
    }
    return *this;
}

// Destructor
Form::~Form() = default;

// Getters
const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

// beSigned implementation
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exception Methods
const char* Form::GradeTooHighException::what() const noexcept {
    return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
    return "Form: grade too low";
}

// Overloaded ostream operator
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName()
       << " (signed: " << std::boolalpha << f.getIsSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute()
       << ")";
    return os;
}
