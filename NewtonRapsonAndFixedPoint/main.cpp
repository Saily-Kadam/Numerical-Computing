#include <iostream>
#include "NewtonFixed.hpp"
using namespace std;

int main() {
    // Hardcoded values
    double tolerance = 0.0001;
    double initialGuess = 2.0;
    
    cout << "\n======================================" << endl;
    cout << "FINDING ROOT OF: f(x) = x^3 - x - 2" << endl;
    cout << "Tolerance: " << tolerance << endl;
    cout << "Initial Guess: " << initialGuess << endl;
    cout << "======================================\n" << endl;
    
    // ===== METHOD 1: NEWTON-RAPHSON =====
    cout << "METHOD 1: Newton-Raphson" << endl;
    
    // Create Newton object (child class)
    NewtonRaphson newton(tolerance, initialGuess);
    
    // Find root
    newton.findRoot();
    
    // Show result
    newton.displayResult("NEWTON-RAPHSON");
    
    
    // ===== METHOD 2: FIXED POINT =====
    cout << "METHOD 2: Fixed Point Iteration" << endl;
    
    // Create Fixed Point object (child class)
    FixedPoint fixed(tolerance, initialGuess);
    
    // Find root
    fixed.findRoot();
    
    // Show result
    fixed.displayResult("FIXED POINT");
    
    
    // ===== SHOWING POLYMORPHISM =====
    cout << "===== BONUS: Polymorphism Demo =====" << endl;
    cout << "Using parent pointer to call child methods\n" << endl;
    
    // Parent pointer
    NumericalMethod* method;
    
    // Point to Newton child
    method = new NewtonRaphson(0.001, 1.5);
    method->findRoot();  // Calls Newton's version
    method->displayResult("Polymorphic Newton");
    delete method;
    
    // Point to Fixed Point child
    method = new FixedPoint(0.001, 1.5);
    method->findRoot();  // Calls Fixed Point's version
    method->displayResult("Polymorphic Fixed Point");
    delete method;
    
    return 0;
}
