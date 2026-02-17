#include <iostream>
#include "all.hpp"
using namespace std;

int main() {
    double tol = 0.0001;
    int choice;

    cout << "Choose method:\n";
    cout << "1. Bisection\n";
    cout << "2. Newton-Raphson\n";
    cout << "3. Fixed Point\n";
    cin >> choice;

    NumericalMethod* obj = nullptr;

    if (choice == 1) {
        obj = new Bisection(tol);

        // Only Bisection needs bounds
        Bisection* bptr = dynamic_cast<Bisection*>(obj);
        if (bptr) bptr->findBounds();
    }
    else if (choice == 2) {
        obj = new NewtonRaphson(1.0, tol);
    }
    else if (choice == 3) {
        obj = new FixedPoint(1.0, tol);
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    obj->findRoot();   // Virtual function call

    if (choice == 1)
        obj->displayResult("BISECTION METHOD");
    else if (choice == 2)
        obj->displayResult("NEWTON-RAPHSON METHOD");
    else
        obj->displayResult("FIXED POINT METHOD");

    delete obj;   // clean memory
    return 0;
}