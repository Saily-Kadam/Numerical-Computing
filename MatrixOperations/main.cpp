#include <iostream>
#include "matrix.hpp"
using namespace std;

int main() {

    int rows1, cols1, rows2, cols2;

    cout << "Matrix 1" << endl;
    cout << "Enter number of rows: ";    cin >> rows1;
    cout << "Enter number of columns: "; cin >> cols1;
    Matrix mat1(rows1, cols1);
    cout << "\nEnter values for Matrix 1:" << endl;
    mat1.takeInput();

    cout << "\nMatrix 2" << endl;
    cout << "Enter number of rows: ";    cin >> rows2;   
    cout << "Enter number of columns: "; cin >> cols2;
    Matrix mat2(rows2, cols2);
    cout << "\nEnter values for Matrix 2:" << endl;
    mat2.takeInput();

    cout << "\nMatrix 1:" << endl;
    mat1.display();
    cout << "\nMatrix 2:" << endl;
    mat2.display();


    cout << "\n ADDITION" << endl;
    try {
        Matrix addResult = mat1 + mat2;
        addResult.display();
    }
    catch (MatrixException& e) {
        cout << "Error: " << e.getMessage() << endl;
    }


    cout << "\n SUBTRACTION" << endl;
    try {
        Matrix subResult = mat1 - mat2;
        subResult.display();
    }
    catch (MatrixException& e) {
        cout << "Error: " << e.getMessage() << endl;
    }


    cout << "\n COPY CONSTRUCTOR " << endl;
    Matrix mat3(mat1);                     
    cout << "mat3 (copy of mat1):" << endl;
    mat3.display();


    cout << "\n ASSIGNMENT OPERATOR " << endl;
    Matrix mat4(1, 1);                      
    mat4 = mat1;                            
    cout << "mat4 after  mat4 = mat1:" << endl;
    mat4.display();

    mat4 = mat4;
    cout << "mat4:" << endl;
    mat4.display();

    cout << "\n GAUSSIAN ELIMINATION " << endl;
    int n;
    cout << "Enter number of equations (variables): ";
    cin >> n;

    GaussianElimination gauss(n);
    gauss.takeInput();
    gauss.compute();
    gauss.displayResult();


    cout << "\n Done!" << endl;
    return 0;
}