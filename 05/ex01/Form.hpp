#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    // Constructor
    explicit Form(const std::string& name, int gradeToSign, int gradeToExecute);
    
    // Copy Constructor and Copy Assignment Operator (Rule of 3)
    Form(const Form& other);
    Form& operator=(const Form& other);

    virtual ~Form(); // Virtual Destructor
    
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    void beSigned(const Bureaucrat& b);

    // Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException() noexcept = default;
        virtual ~GradeTooHighException() noexcept = default;
        virtual const char* what() const noexcept override;
    };
    
    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException() noexcept = default;
        virtual ~GradeTooLowException() noexcept = default;
        virtual const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);


