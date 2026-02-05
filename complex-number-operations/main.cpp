#include <iostream>
#include "complex.hpp"

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    Complex sum  = c1.add(c2);
    Complex diff = c1.subtract(c2);
    Complex prod = c1.multiply(c2);
    Complex quot = c1.divide(c2);
    std::cout << "\nConjugate of c1: ";


    std::cout << "c1 = ";
    c1.display();

    std::cout << "c2 = ";
    c2.display();

    std::cout << "\nAddition: ";
    sum.display();

    std::cout << "Subtraction: ";
    diff.display();

    std::cout << "Multiplication: ";
    prod.display();

    std::cout << "Division: ";
    quot.display();

    std::cout << "\nNorm of c1: " << c1.norm() << std::endl;
    std::cout << "Norm of c2: " << c2.norm() << std::endl;
    std::cout << "Conjugate of c1: ";
    c1.conjugate().display();
    std::cout << "Conjugate of c2: ";
    c2.conjugate().display();

    return 0;
}
