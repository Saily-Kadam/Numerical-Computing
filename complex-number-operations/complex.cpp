#include "complex.hpp"
#include <iostream>
#include <cmath>

// Default constructor
Complex::Complex() {
    real = 0.0;
    imag = 0.0;
}

// Parameterized constructor
Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

// Addition
Complex Complex::add(const Complex& c) const {
    return Complex(real + c.real, imag + c.imag);
}

// Subtraction
Complex Complex::subtract(const Complex& c) const {
    return Complex(real - c.real, imag - c.imag);
}

// Multiplication
Complex Complex::multiply(const Complex& c) const {
    double r = real * c.real - imag * c.imag;
    double i = real * c.imag + imag * c.real;
    return Complex(r, i);
}

// Division
Complex Complex::divide(const Complex& c) const {
    double denom = c.real * c.real + c.imag * c.imag;
    return Complex(
        (real * c.real + imag * c.imag) / denom,
        (imag * c.real - real * c.imag) / denom
    );
}

// Norm
double Complex::norm() const {
    return std::sqrt(real * real + imag * imag);
}

// Complex conjugate
// -------- Complex conjugate --------
Complex Complex::conjugate() const {
    // Conjugate of (a + bi) is (a - bi)
    return Complex(real, -imag);
}


// Display
void Complex::display() const {
    std::cout << real
              << (imag >= 0 ? " + " : " - ")
              << std::abs(imag) << "i\n";
}
