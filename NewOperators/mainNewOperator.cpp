#include "matrix.hpp"
#include <iostream>
using namespace std;

int main() {

    int folderChoice;
    cout << "Select folder:" << endl;
    cout << "1. 49" << endl;
    cout << "2. 225" << endl;
    cin >> folderChoice;

    string inputFileA, inputFileB, outputFile;

    if (folderChoice == 1) {
        inputFileA = "49/inputl.txt";
        //inputFileB = "49/inputr.txt";
        outputFile = "49/output2.txt";
    } else {
        inputFileA = "225/225left.txt";
        inputFileB = "225/225right.txt";
        outputFile = "225/output.txt";
    }

    try {
        ifstream inA(inputFileA);
        if (!inA.is_open())
            throw runtime_error("Cannot open file: " + inputFileA);
        Matrix A;
        inA >> A;
        inA.close();

        cout << "\nMatrix A " << endl;
        cout << A;

        Matrix B;
        B = A;
        cout << "\nMatrix B " << endl;
        cout << B;

    
        cout << "\nDeep Copy Verify" << endl;
        B(0, 0) = 999.0;
        cout << "A(0,0) after modifying B(0,0): " << A(0, 0) << "  (should be unchanged)" << endl;
        cout << "B(0,0) after modification    : " << B(0, 0) << endl;

        cout << "\noperator() Read: A(0,0) = " << A(0, 0) << endl;

        A(0, 0) = -1.0;
        cout << "\n=== Matrix A after A(0,0) = -1 (operator() write)" << endl;
        cout << A;

        // ── Read second matrix and test operator= chain
        ifstream inB(inputFileB);
        if (!inB.is_open())
            throw runtime_error("Cannot open file: " + inputFileB);
        Matrix C;
        inB >> C;
        inB.close();
        cout << "\n=== Matrix C (read from second file) ===" << endl;
        cout << C;

        // ── Write results to output file via operator<< 
        ofstream out(outputFile);
        if (!out.is_open())
            throw runtime_error("Cannot open output file: " + outputFile);

        out << "Matrix A (after modification):\n" << A << "\n";
        out << "Matrix B (copy of original A, B(0,0)=999):\n" << B << "\n";
        out << "Matrix C (second input):\n" << C << "\n";
        out.close();

        cout << "\nResults written to: " << outputFile << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}