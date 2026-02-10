#include <iostream>
#include "bisection.hpp"
using namespace std;

int main() {
    // Only tolerance is hardcoded
    double tolerance = 0.0001;    // Tolerance (stopping criteria)
    
    cout << "Bisection Method Program" << endl;
    cout << "Finding root of f(x) = x^4-3x" << endl;
    cout << "Tolerance: " << tolerance << endl;
    
    // Create Bisection object with only tolerance
    Bisection bisect(tolerance);
    
    // Automatically find the bounds
    bisect.findBounds();
    
    // Find the root
    bisect.findRoot();
    
    // Display results
    bisect.displayResult();
    
    return 0;
}
