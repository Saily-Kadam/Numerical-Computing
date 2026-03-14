#include "matrix.hpp"
// Prints matrix
ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.matrix[i][j];
            if (j < m.cols - 1) os << "\t";
        }
        os << "\n";
    }
    return os;
}
//Read matrix
istream& operator>>(istream& is, Matrix& m) {
    is >> m.rows >> m.cols;
    if (m.rows <= 0 || m.cols <= 0)
        throw invalid_argument("Rows and cols must be positive.");

    m.matrix.assign(m.rows, vector<double>(m.cols, 0.0));
    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
            is >> m.matrix[i][j];

    return is;
}
//Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other)
        return *this;
    rows   = other.rows;
    cols   = other.cols;
    matrix = other.matrix;
    return *this;
}
//Element Access
double& Matrix::operator()(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw out_of_range("Index out of range in operator().");
    return matrix[r][c];
}
//read and write the matrix
const double& Matrix::operator()(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw out_of_range("Index out of range in operator() const.");
    return matrix[r][c];
}