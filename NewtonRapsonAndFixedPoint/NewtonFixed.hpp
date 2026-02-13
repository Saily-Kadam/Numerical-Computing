#ifndef METHODS_HPP
#define METHODS_HPP

// Don't skip this! Prevents errors if file is included multiple times
// #include <string> is needed because we use "string" data type below

#include <string>

// ========== BASE CLASS (PARENT) ==========
// This is the parent class - both methods inherit from this
class NumericalMethod {
protected:
    // Protected = children can access these
    double tolerance;      // How accurate we want (e.g., 0.0001)
    double root;          // The answer we find
    int iterations;       // How many steps it took
    double initialGuess;  // Starting point (e.g., 2.0)
    
public:
    // Constructor - sets up initial values
    NumericalMethod(double tol, double guess);
    
    // The equation we're solving: f(x) = x^3 - x - 2
    // We want to find x where f(x) = 0
    double function(double x);
    
    // PURE VIRTUAL - each child MUST write their own version
    // This makes the class "abstract" - can't create objects directly
    virtual void findRoot() = 0;
    
    // Show the results - same for everyone
    void displayResult(std::string methodName);
};

// ========== CHILD CLASS 1: NEWTON-RAPHSON ==========
// "public NumericalMethod" means it inherits from parent
class NewtonRaphson : public NumericalMethod {
public:
    // Constructor
    NewtonRaphson(double tol, double guess);
    
    // Newton needs derivative: f'(x) = 3x^2 - 1
    double derivative(double x);
    
    // "override" means we're writing our own version of findRoot
    void findRoot() override;
};

// ========== CHILD CLASS 2: FIXED POINT ==========
class FixedPoint : public NumericalMethod {
public:
    // Constructor
    FixedPoint(double tol, double guess);
    
    // Fixed Point needs g(x) = cube_root(x + 2)
    double g_function(double x);
    
    // Our own version of findRoot
    void findRoot() override;
};

#endif
