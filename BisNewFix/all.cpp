#include "all.hpp"
#include <iostream>
#include <cmath>
using namespace std;

//BASE CLASS IMPLEMENTATION 

// Constructor
NumericalMethod::NumericalMethod(double tol) {
    tolerance = tol;
    root = 0.0;
    iterations = 0;
}


double NumericalMethod::function(double x) {
    return x * x * x - x - 2;
}

// Display results
void NumericalMethod::displayResult(string methodName) {
    cout << "\n " << methodName << " RESULTS" << endl;
    cout << "Root: " << root << endl;
    cout << "Iterations: " << iterations << endl;
    cout << "f(root) = " << function(root) << endl;
}

// BISECTION METHOD IMPLEMENTATION 

// Constructor 
Bisection::Bisection(double tol) 
    : NumericalMethod(tol) {
    a = 0.0;
    b = 0.0;
}

// Automatically find bounds where root exists
void Bisection::findBounds() {
    double x = 0.0;
    double step = 0.5;  // Step size for searching
    bool found = false;
    
    // Search in positive direction first
    for (x = 0.0; x <= 10.0; x += step) {
        double f1 = function(x);
        double f2 = function(x + step);
        
        // Check if function changes sign
        if (f1 * f2 < 0) {
            a = x;
            b = x + step;
            found = true;
            cout << "Found interval in positive direction" << endl;
            break;
        }
    }
    
    // If not found, search in negative direction
    if (!found) {
        for (x = 0.0; x >= -10.0; x -= step) {
            double f1 = function(x);
            double f2 = function(x - step);
            
            if (f1 * f2 < 0) {
                a = x - step;
                b = x;
                found = true;
                cout << "Found interval in negative direction!" << endl;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "No interval found" << endl;
    } else {
        cout << "Interval found: [" << a << ", " << b << "]" << endl;
        cout << "f(" << a << ") = " << function(a) << endl;
        cout << "f(" << b << ") = " << function(b) << endl;
    }
}

// Bisection Algorithm
void Bisection::findRoot() {
    double fa = function(a);
    double fb = function(b);
    
    // Check if root exists
    if (fa * fb > 0) {
        cout << "Error: No root in this interval" << endl;
        return;
    }
    
    double c;   // Midpoint
    double fc;  // Function value at midpoint
    
    // Keep bisecting until close enough
    while (fabs(b - a) >= tolerance) {
        c = (a + b) / 2.0;  // Calculate midpoint
        fc = function(c);    // Calculate f(c)
        
        iterations++;
        
        // Found exact root
        if (fc == 0.0) {
            break;
        }
        
        // Decide which half contains root
        if (function(a) * fc < 0) {
            b = c;  // Root in left half
        } else {
            a = c;  // Root in right half
        }
    }
    
    root = (a + b) / 2.0;  // Final answer
}

// NEWTON-RAPHSON IMPLEMENTATION

// Constructor
NewtonRaphson::NewtonRaphson(double guess, double tol) 
    : NumericalMethod(tol) {
    initialGuess = guess;
}

// Derivative: f'(x) = 3x^2 - 1
double NewtonRaphson::derivative(double x) {
    return 3 * x * x - 1;
}

// Newton-Raphson Algorithm: x_new = x - f(x)/f'(x)
void NewtonRaphson::findRoot() {
    double x = initialGuess;
    
    while (true) {
        double fx = function(x);      // Calculate f(x)
        double fpx = derivative(x);   // Calculate f'(x)
        
        // Check derivative not zero
        if (fabs(fpx) < 0.0000000001) {
            cout << "Derivative is zero" << endl;
            return;
        }
        
        // Newton formula
        double x_new = x - fx / fpx;
        
        iterations++;
        
        // Check if close enough
        if (fabs(x_new - x) < tolerance) {
            root = x_new;
            break;
        }
        
        x = x_new;  // Update for next iteration
        
        
        if (iterations > 100) {
            root = x;
            break;
        }
    }
}

// FIXED POINT IMPLEMENTATION 

// Constructor
FixedPoint::FixedPoint(double guess, double tol) 
    : NumericalMethod(tol) {
    initialGuess = guess;
}

// Transform to x = g(x) form: g(x) = cube_root(x + 2)
double FixedPoint::g_function(double x) {
    return pow(x + 2, 1.0/3.0);
}

// Fixed Point Algorithm: x_new = g(x)
void FixedPoint::findRoot() {
    double x = initialGuess;
    
    while (true) {
        double x_new = g_function(x);  // Apply g(x)
        
        iterations++;
        
        // Check if close enough
        if (fabs(x_new - x) < tolerance) {
            root = x_new;
            break;
        }
        
        x = x_new;  // Update for next iteration
        

        if (iterations > 100) {
            root = x;
            break;
        }
    }
}
