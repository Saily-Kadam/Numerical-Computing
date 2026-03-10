#include "matrix.hpp"

Crout::Crout(string filename) : LUDecomposition(filename) {}

void Crout::decompose(string outputFile) {
    ofstream fout(outputFile);
    if (!fout) throw runtime_error("Cannot open output file: " + outputFile);
    try {
        for (int j = 0; j < n; j++) {
            // Upper triangular matrix U (diagonal = 1)
            U[j][j] = 1.0;
            // Lower triangular matrix L
            for (int i = j; i < n; i++) {
                double sum = 0.0;
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * U[k][j];
                L[i][j] = matrix[i][j] - sum;
            }
            // Upper triangular matrix U
            for (int i = j + 1; i < n; i++) {
                if (abs(L[j][j]) < 1e-12)
                    throw runtime_error("Zero pivot encountered! Crout decomposition failed.");
                double sum = 0.0;
                for (int k = 0; k < j; k++)
                    sum += L[j][k] * U[k][i];
                U[j][i] = (matrix[j][i] - sum) / L[j][j];
            }
        }
        fout << "Crout Decomposition:" << endl;
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