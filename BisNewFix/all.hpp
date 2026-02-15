#include <string>

//BASE CLASS 
class NumericalMethod {
protected:
    double tolerance;      
    double root;          
    int iterations;       
    
public:
    // Constructor
    NumericalMethod(double tol);
    
    // The equation: f(x) = x^3 - x - 2
    double function(double x);
    
    // PURE VIRTUAL 
    virtual void findRoot() = 0;
    
    // Display results
    void displayResult(std::string methodName);
    
    
};

// CLASS 1: BISECTION
class Bisection : public NumericalMethod {
private:
    double a;  
    double b;  
    
public:
    // Constructor
    Bisection(double tol);
    
    // for finding intervals
    void findBounds();
    
    // Override findRoot 
    void findRoot() override;
};

//CHILD CLASS 2: NEWTON-RAPHSON
class NewtonRaphson : public NumericalMethod {
private:
    double initialGuess;  // Starting point
    
public:
    // Constructor
    NewtonRaphson(double guess, double tol);
    
    // Derivative 
    double derivative(double x);
    
    // Override findRoot 
    void findRoot() override;
};

//CHILD CLASS 3: FIXED POINT
class FixedPoint : public NumericalMethod {
private:
    double initialGuess;  // Starting point
    
public:
    // Constructor
    FixedPoint(double guess, double tol);
    
    // Transform to x = g(x) form
    double g_function(double x);
    
    // Override findRoot 
    void findRoot() override;
};