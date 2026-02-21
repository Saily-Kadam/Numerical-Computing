#include <string>
using namespace std;

class MatrixException {
private:
    string message;

public:
    MatrixException(string msg) {
        this->message = msg;   
    }

    string getMessage() {
        return message;
    }
};

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    // Constructor
    Matrix(int r, int c);

    // Copy Constructor
    Matrix(const Matrix& other);

    // Destructor
    ~Matrix();

    // Assignment 
    Matrix& operator=(const Matrix& other);

    
    int getRows();

    int getCols();

    void takeInput();

    void display();

    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
};



class GaussianElimination {
private:
    int n;            // number of equations
    double** mat;     // augmented matrix 
    double* solution; // stores final answers x1, x2, x3...

public:
    GaussianElimination(int size);
    ~GaussianElimination();
    void takeInput();
    void compute();
    void displayResult();
};
