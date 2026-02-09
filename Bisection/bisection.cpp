#include "bisection.hpp"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor - initializes only tolerance
Bisection::Bisection(double tol) {
    tolerance = tol;
    root = 0.0;
    iterations = 0;
    a = 0.0;
    b = 0.0;
}

// Hardcoded function: f(x) = 4x^3-3x
// We want to find where this function equals zero
double Bisection::function(double x) {
    return 4*x*x*x-3*x;
}

// Automatically find bounds where root exists
void Bisection::findBounds() {
    cout << "\nSearching for interval containing root..." << endl;
    
    // Start from x = 0 and search in both directions
    double x = 0.0;
    double step = 0.5;  // Step size for searching
    
    // Search in positive direction first
    bool found = false;
    
    for (x = 0.0; x <= 10.0; x += step) {
        double f1 = function(x);
        double f2 = function(x + step);
        
        // Check if function changes sign (root exists between x and x+step)
        if (f1 * f2 < 0) {
            a = x;
            b = x + step;
            found = true;
            cout << "Found interval in positive direction!" << endl;
            break;
        }
    }
    
    // If not found in positive direction, search in negative direction
    if (!found) {
        for (x = 0.0; x >= -10.0; x -= step) {
            double f1 = function(x);
            double f2 = function(x - step);
            
            // Check if function changes sign
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
        cout << "Could not find suitable interval!" << endl;
    
    } else {
        cout << "Interval found: [" << a << ", " << b << "]" << endl;
        cout << "f(" << a << ") = " << function(a) << endl;
        cout << "f(" << b << ") = " << function(b) << endl;
    }
}

// Main bisection method algorithm
void Bisection::findRoot() {
    double fa = function(a);  // Value of function at point 'a'
    double fb = function(b);  // Value of function at point 'b'
    
    // Check if root exists between a and b
    if (fa * fb > 0) {
        cout << "Error" << endl;
        
        return;
    }
    
    double c;  // Midpoint
    double fc; // Function value at midpoint
    
    // Keep bisecting until we reach desired tolerance
    while (abs(b - a) >= tolerance) {
        // Calculate midpoint
        c = (a + b) / 2.0;
        
        // Calculate function value at midpoint
        fc = function(c);
        
        iterations++;
        
        // Check if we found exact root
        if (fc == 0.0) {
            break;
        }
        
        // Decide which half to keep
        // If f(a) and f(c) have opposite signs, root is in left half
        if (function(a) * fc < 0) {
            b = c;  // Root is in left half
        } else {
            a = c;  // Root is in right half
        }
    }
    
    // Store the final root
    root = (a + b) / 2.0;
}

// Display the results
void Bisection::displayResult() {
    cout << "\n========== BISECTION METHOD ==========" << endl;
    cout << "Function: f(x) = x^4-3x" << endl;
    cout << "Root found: " << root << endl;
    cout << "Number of iterations: " << iterations << endl;
    cout << "Function value at root: " << function(root) << endl;
    
}
