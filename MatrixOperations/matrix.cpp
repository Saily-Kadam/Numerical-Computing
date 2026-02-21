#include "matrix.hpp"
#include <iostream>

using namespace std;

// Constructor

Matrix::Matrix(int r, int c) {
    this->rows = r;
    this->cols = c;

    data = new int*[rows];        // array of row pointers
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];  // allocate each row
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0;       
        }
    }
}
// Copy Constructor

Matrix::Matrix(const Matrix& other) {
    this->rows = other.rows;
    this->cols = other.cols;

    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];  // copy each value
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];  // each row
    }
    delete[] data;         // array of row pointers
}

// Assignment Operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {   
        return *this;
    }

    // free memory
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;

    // copy values
    rows = other.rows;
    cols = other.cols;

    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

int Matrix::getRows() {
    return rows;
}

int Matrix::getCols() {
    return cols;
}

void Matrix::takeInput() {
    cout << "Enter values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "  [" << i+1 << "][" << j+1 << "]: ";
            cin >> data[i][j];
        }
    }
}

void Matrix::display() {
    for (int i = 0; i < rows; i++) {
        cout << "| ";
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << "\t";
        }
        cout << "|" << endl;
    }
}