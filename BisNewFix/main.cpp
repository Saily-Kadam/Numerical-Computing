#include <iostream>
#include "all.hpp"
using namespace std;

int main() {
   
    double tolerance = 0.0001;
    
    cout << "Finding root of: f(x) = x^3 - x - 2" << endl;
    cout << "Tolerance: " << tolerance << endl;
    
    
    
    // METHOD 1: BISECTION 
    cout << "METHOD 1: BISECTION " << endl;
    
    // Bisection object 
    Bisection bisect(tolerance);
    
    // find the interval
    bisect.findBounds();
    
    // Find root
    bisect.findRoot();
    
    // Display result
    bisect.displayResult("BISECTION METHOD");
    
    
    // METHOD 2: NEWTON-RAPHSON 
    cout << "\nMETHOD 2: NEWTON-RAPHSON" << endl;
    cout << "Initial guess: 1.0" << endl;
    
    NewtonRaphson newton(1.0, tolerance);
    newton.findRoot();
    newton.displayResult("NEWTON-RAPHSON METHOD");
    
    
    // METHOD 3: FIXED POINT
    cout << "\n METHOD 3: FIXED POINT ITERATION " << endl;
    cout << "Initial guess: 1.0" << endl;
    
    FixedPoint fixed(1.0, tolerance);
    fixed.findRoot();
    fixed.displayResult("FIXED POINT METHOD");
    return 0;
}
