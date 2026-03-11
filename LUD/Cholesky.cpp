#include "matrix.hpp"
#include<cmath>
Cholesky::Cholesky(string filename) : LUDecomposition(filename) {}

void Cholesky::decompose(string outputFile) {
    ofstream fout(outputFile);
    if (!fout) throw runtime_error("Cannot open output file: " + outputFile);
    try {
        // Check if matrix is symmetric
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (abs(matrix[i][j] - matrix[j][i]) > 1e-9)
                    throw runtime_error("Matrix is not symmetric! Cholesky decomposition requires a symmetric positive definite matrix.");
        // Cholesky decomposition: A = L * L^T
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                double sum = 0.0;
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                if (i == j) {
                    double val = matrix[i][i] - sum;
                    if (val <= 0)
                        throw runtime_error("Matrix is not positive definite! Cholesky decomposition failed.");
                    L[i][j] = sqrt(val);
                } else {
                    if (abs(L[j][j]) < 1e-12)
                        throw runtime_error("Zero diagonal encountered! Cholesky decomposition failed.");
                    L[i][j] = (matrix[i][j] - sum) / L[j][j];
                }
            }
        }
        // U = L^T
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                U[i][j] = L[j][i];

        fout << "Cholesky Decomposition (A = L * L^T):" << endl;
        fout << "\nL Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fout << L[i][j];
                if (j < n - 1) fout << " ";
            }
            fout << endl;
        }
        fout << "\nL^T Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fout << U[i][j];
                if (j < n - 1) fout << " ";
            }
            fout << endl;
        }
    }
    catch (exception& e) {
        fout << "Error: " << e.what() << endl;
    }
    fout.close();
}