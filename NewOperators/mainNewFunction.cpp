#include "matrix.hpp"
#include <iostream>
using namespace std;

void printBool(const string& label, bool val) {
    cout << label << ": " << (val ? "YES" : "NO") << endl;
}

void writeBool(ofstream& out, const string& label, bool val) {
    out << label << ": " << (val ? "YES" : "NO") << "\n";
}

int main() {

    int folderChoice;
    cout << "Select folder:" << endl;
    cout << "1. 49" << endl;
    cout << "2. 225" << endl;
    cin >> folderChoice;

    string inputFile, outputFile;

    if (folderChoice == 1) {
        inputFile  = "49/inputl.txt";
        outputFile = "49/output2.txt";
    } else {
        inputFile  = "225/225left.txt";
        outputFile = "225/output.txt";
    }

    try {
        // ── Read matrix from file 
        ifstream in(inputFile);
        if (!in.is_open())
            throw runtime_error("Cannot open file: " + inputFile);
        Matrix A;
        in >> A;
        in.close();

        cout << "\nMatrix A" << endl;
        cout << A;

        ofstream out(outputFile);
        if (!out.is_open())
            throw runtime_error("Cannot open output file: " + outputFile);

        out << "Matrix A:\n" << A << "\n";

        // Boolean Checks 
        cout << "\nBoolean Checks" << endl;
        out  << "Boolean Checks\n";

        printBool("isSquare",A.isSquare());
        printBool("isNull",A.isNull());
        printBool("isIdentity",A.isIdentity());
        printBool("isDiagonal",A.isDiagonal());
        printBool("isDiagonallyDominant",A.isDiagonallyDominant());

        writeBool(out, "isSquare",A.isSquare());
        writeBool(out, "isNull",A.isNull());
        writeBool(out, "isIdentity",A.isIdentity());
        writeBool(out, "isDiagonal",A.isDiagonal());
        writeBool(out, "isDiagonallyDominant", A.isDiagonallyDominant());

        //Transpose 
        cout << "\nTranspose" << endl;
        out  << "\nTranspose\n";
        Matrix T = A.Transpose();
        cout << T;
        out  << T << "\n";

        //Determinant 
        cout << "\nDeterminant" << endl;
        out  << "Determinant\n";
        try {
            double det = A.Determinant();
            cout << "det(A) = " << det << endl;
            out  << "det(A) = " << det << "\n";
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            out  << "Error: " << e.what() << "\n";
        }

        //Inverse 
        cout << "\nInverse" << endl;
        out  << "\nInverse\n";
        try {
            Matrix inv = A.Inverse();
            cout << inv;
            out  << inv << "\n";
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            out  << "Error: " << e.what() << "\n";
        }

        //makeDiagonallyDominant 
        cout << "\nMake Diagonally Dominant" << endl;
        out  << "Make Diagonally Dominant\n";
        Matrix B = A;
        try {
            B.makeDiagonallyDominant();
            cout << "After makeDiagonallyDominant:\n" << B;
            out  << "After makeDiagonallyDominant:\n" << B << "\n";
            printBool("isDiagonallyDominant now", B.isDiagonallyDominant());
            writeBool(out, "isDiagonallyDominant now", B.isDiagonallyDominant());
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            out  << "Error: " << e.what() << "\n";
        }

        out.close();
        cout << "\nResults written to: " << outputFile << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}