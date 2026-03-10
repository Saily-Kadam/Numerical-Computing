#include "matrix.hpp"

Doolittle::Doolittle(string filename) : LUDecomposition(filename) {}

void Doolittle::decompose(string outputFile) {
    ofstream fout(outputFile);
    if (!fout) throw runtime_error("Cannot open output file: " + outputFile);
    try {
        for (int i = 0; i < n; i++) {
            // Upper triangular matrix U
            for (int k = i; k < n; k++) {
                double sum = 0.0;
                for (int j = 0; j < i; j++)
                    sum += L[i][j] * U[j][k];
                U[i][k] = matrix[i][k] - sum;
            }
            // Lower triangular matrix L (diagonal = 1)
            L[i][i] = 1.0;
            for (int k = i + 1; k < n; k++) {
                if (abs(U[i][i]) < 1e-12)
                    throw runtime_error("Zero pivot encountered! Doolittle decomposition failed.");
                double sum = 0.0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];
                L[k][i] = (matrix[k][i] - sum) / U[i][i];
            }
        }
        fout << "Doolittle Decomposition:" << endl;
        fout << "\nL Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fout << L[i][j];
                if (j < n - 1) fout << " ";
            }
            fout << endl;
        }
        fout << "\nU Matrix:" << endl;
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