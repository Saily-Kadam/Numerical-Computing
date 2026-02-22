#include "matrix.hpp"
#include <cmath>   
#include <iostream>

using namespace std;

GaussianElimination::GaussianElimination(int size) {
    this->n = size;

    mat = new double*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new double[n + 1];  
        for (int j = 0; j <= n; j++) {
            mat[i][j] = 0.0;
        }
    }

    solution = new double[n];
    for (int i = 0; i < n; i++) {
        solution[i] = 0.0;
    }
}

GaussianElimination::~GaussianElimination() {
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    delete[] solution;
}


void GaussianElimination::takeInput() {
    cout << "\nEnter the augmented matrix " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
}

void GaussianElimination::compute() {
    try {

        // Forward Elimination
        for (int col = 0; col < n; col++) {
            if (fabs(mat[col][col]) < 0.0000001) {
                throw MatrixException("Zero on diagonal.");
            }

            
            for (int row = col + 1; row < n; row++) {
                double factor = mat[row][col] / mat[col][col];
                for (int j = col; j <= n; j++) {
                    mat[row][j] = mat[row][j] - factor * mat[col][j];
                }
            }
        }

        //Back Substitution
        for (int i = n - 1; i >= 0; i--) {
            solution[i] = mat[i][n];   // start with the answer column
            for (int j = i + 1; j < n; j++) {
                solution[i] = solution[i] - mat[i][j] * solution[j];
            }
            solution[i] = solution[i] / mat[i][i];
        }

    }
    catch (MatrixException& e) {
        cout << "Error: " << e.getMessage() << endl;
    }
}


void GaussianElimination::displayResult() {
    cout << "\n SOLUTION" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  x" << i + 1 << " = " << solution[i] << endl;
    }
}