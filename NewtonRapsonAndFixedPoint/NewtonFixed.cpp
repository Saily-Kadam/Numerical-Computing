#include "NewtonFixed.hpp"
#include <iostream>
#include <cmath>
using namespace std;

// ========== BASE CLASS CODE ==========

// Constructor - initialize all variables
NumericalMethod::NumericalMethod(double tol, double guess) {
    tolerance = tol;
    initialGuess = guess;
    root = 0.0;
    iterations = 0;
}

// The equation: f(x) = x^3 - x - 2
double NumericalMethod::function(double x) {
    return x * x * x - x - 2;
}

// Display results
void NumericalMethod::displayResult(string methodName) {
    cout << "\n===== " << methodName << " RESULTS =====" << endl;
    cout << "Root: " << root << endl;
    cout << "Iterations: " << iterations << endl;
    cout << "f(root) = " << function(root) << endl;
    cout << "================================\n" << endl;
}

// ========== NEWTON-RAPHSON CODE ==========

// Constructor - call parent constructor first
NewtonRaphson::NewtonRaphson(double tol, double guess) 
    : NumericalMethod(tol, guess) {
    // Parent constructor already set everything!
}

// Derivative: f'(x) = 3x^2 - 1
double NewtonRaphson::derivative(double x) {
    return 3 * x * x - 1;
}

// Newton-Raphson formula: x_new = x_old - f(x)/f'(x)
void NewtonRaphson::findRoot() {
    double x = initialGuess;  // Start here
    
    // Loop until we get close enough
    while (true) {
        double fx = function(x);      // Calculate f(x)
        double fpx = derivative(x);   // Calculate f'(x)
        
        // New approximation
        double x_new = x - fx / fpx;
        
        iterations++;  // Count this step
        
        // Are we close enough?
        if (fabs(x_new - x) < tolerance) {
            root = x_new;  // Found it!
            break;
        }
        
        x = x_new;  // Try again with new value
        
        // Safety: stop after 100 tries
        if (iterations > 100) {
            root = x;
            break;
        }
    }
}

// ========== FIXED POINT CODE ==========

// Constructor - call parent constructor first
FixedPoint::FixedPoint(double tol, double guess) 
    : NumericalMethod(tol, guess) {
    // Parent constructor already set everything!
}

// Transform equation to x = g(x) form
// g(x) = cube_root(x + 2)
double FixedPoint::g_function(double x) {
    return pow(x + 2, 1.0/3.0);
}

// Fixed Point formula: x_new = g(x_old)
void FixedPoint::findRoot() {
    double x = initialGuess;  // Start here
    
    // Loop until we get close enough
    while (true) {
        double x_new = g_function(x);  // Apply g(x)
        
        iterations++;  // Count this step
        
        // Are we close enough?
        if (fabs(x_new - x) < tolerance) {
            root = x_new;  // Found it!
            break;
        }
        
        x = x_new;  // Try again with new value
        
        // Safety: stop after 100 tries
        if (iterations > 100) {
            root = x;
            break;
        }
    }
}
