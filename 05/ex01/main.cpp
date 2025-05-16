#include "Bureaucrat.hpp"
#include "Form.hpp"

void printDivider(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    // Test 1: Valid form signing
    printDivider("Test 1: Valid Bureaucrat signs a valid Form");
    try {
        Bureaucrat b1("Alice", 50);
        Form f1("FormA", 60, 70);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 2: Bureaucrat with too low grade tries to sign
    printDivider("Test 2: Low-grade Bureaucrat cannot sign Form");
    try {
        Bureaucrat b2("Bob", 100);
        Form f2("SecretForm", 50, 60);

        b2.signForm(f2);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Form creation with too high grade
    printDivider("Test 3: Create Form with grade too high (0)");
    try {
        Form f3("BadForm", 0, 10); // Invalid: 0 is too high
    } catch (std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    // Test 4: Form creation with too low grade
    printDivider("Test 4: Create Form with grade too low (151)");
    try {
        Form f4("AnotherBadForm", 151, 150); // Invalid: 151 is too low
    } catch (std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    // Test 5: Bureaucrat incrementing beyond max
    printDivider("Test 5: Bureaucrat increment beyond grade 1");
    try {
        Bureaucrat b3("Carol", 1);
        b3.incrementGrade(); // Should throw
    } catch (std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    // Test 6: Bureaucrat decrementing beyond min
    printDivider("Test 6: Bureaucrat decrement below grade 150");
    try {
        Bureaucrat b4("Dave", 150);
        b4.decrementGrade(); // Should throw
    } catch (std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
