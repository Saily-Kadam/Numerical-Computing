#include "matrix.hpp"

int main() {
    int operationChoice;
    cout << "Select LU Decomposition method:" << endl;
    cout << "1. Doolittle Decomposition" << endl;
    cout << "2. Crout Decomposition" << endl;
    cout << "3. Cholesky Decomposition" << endl;
    cin >> operationChoice;

    try {
        int inputChoice;
        cout << "\nHow do you want to provide the matrix?" << endl;
        cout << "1. Enter manually" << endl;
        cout << "2. Load from file" << endl;
        cin >> inputChoice;

        string inputFile, outputFile;

        if (inputChoice == 1) {
            // Write user input to a temp file so LUDecomposition can read it
            Matrix temp;
            temp.takeInputFromUser();
            temp.writeToFile("temp_lu.txt", "");
            inputFile  = "temp_lu.txt";
            outputFile = "output_lu.txt";
        } else {
            int folderChoice;
            cout << "Select folder:" << endl;
            cout << "1. 49" << endl;
            cout << "2. 225" << endl;
            cin >> folderChoice;
            if (folderChoice == 1) {
                inputFile  = "49/49l.txt";
                outputFile = "49/output_lu.txt";
            } else {
                inputFile  = "225/225left.txt";
                outputFile = "225/output_lu.txt";
            }
        }

        if (operationChoice == 1) {
            Doolittle d(inputFile);
            d.decompose(outputFile);
        }
        else if (operationChoice == 2) {
            Crout c(inputFile);
            c.decompose(outputFile);
        }
        else if (operationChoice == 3) {
            Cholesky ch(inputFile);
            ch.decompose(outputFile);
        }
        else {
            throw runtime_error("Invalid operation choice!");
        }

        cout << "Result written to " << outputFile << endl;
    }
    catch (exception& e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}