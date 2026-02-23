#include "matrix.hpp"
#include <iostream>

using namespace std;
//add
Matrix Matrix::operator+(const Matrix& other) {

    if (rows != other.rows || cols != other.cols) {
        throw MatrixException("Cannot add matrices have different dimensions");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}


//subtract
Matrix Matrix::operator-(const Matrix& other) {

    if (rows != other.rows || cols != other.cols) {
        throw MatrixException("Cannot subtract matrices have different orders");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}