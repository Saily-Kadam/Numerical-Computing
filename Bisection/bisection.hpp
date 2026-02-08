
// Class for Bisection Method
class Bisection {
private:
    double a;           // Lower bound
    double b;           // Upper bound
    double tolerance;   // Tolerance for stopping
    double root;        // Final root value
    int iterations;     // Number of iterations taken

public:
    // Constructor
    Bisection(double tol);
    
    // Function whose root we want to find
    // f(x) = 4x^3-3x (hardcoded)
    double function(double x);
    
    // Automatically find interval containing root
    void findBounds();
    
    // Method to find root using bisection
    void findRoot();
    
    // Display the result
    void displayResult();
};