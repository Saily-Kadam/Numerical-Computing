#include "matrix.hpp"

bool Matrix::isSquare()  {
    return rows == cols;
}

bool Matrix::isNull()  {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0.0)
                return false;
    return true;
}

bool Matrix::isIdentity()  {
    if (!isSquare()) return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            if (i == j && matrix[i][j] != 1.0) return false;
            if (i != j && matrix[i][j] != 0.0) return false;
        }
    return true;
}
//offdiagonal are 0
bool Matrix::isDiagonal()  {
    if (!isSquare()) return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i != j && matrix[i][j] != 0.0)
                return false;
    return true;
}
//diagonal element > sum of other elements in that row
bool Matrix::isDiagonallyDominant(){
    if (!isSquare()) return false;
    for (int i = 0; i < rows; i++) {
        double diagVal = abs(matrix[i][i]);
        double offSum  = 0.0;
        for (int j = 0; j < cols; j++)
            if (i != j)
                offSum += abs(matrix[i][j]);
        if (diagVal < offSum)
            return false;
    }
    return true;
}

Matrix Matrix::Transpose() {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.matrix[j][i] = matrix[i][j];
    return result;
}
// make the diagonal elements the largest ones
void Matrix::makeDiagonallyDominant() {
    if (!isSquare())
        throw logic_error("Matrix must be square to make diagonally dominant.");

    for (int i = 0; i < rows; i++) {
        // Find the best row to place at position i
        int bestRow = -1;
        double bestVal = -1.0;
        for (int k = i; k < rows; k++) {
            double diagVal = abs(matrix[k][i]);
            double offSum  = 0.0;
            for (int j = 0; j < cols; j++)
                if (j != i)
                    offSum += abs(matrix[k][j]);
            if (diagVal >= offSum && diagVal > bestVal) {
                bestVal = diagVal;
                bestRow = k;
            }
        }
        if (bestRow == -1)
            throw logic_error("Cannot make matrix diagonally dominant.");
        if (bestRow != i)
            swap(matrix[i], matrix[bestRow]);
    }
}

double Matrix::Determinant() {
    if (!isSquare())
        throw logic_error("Determinant is only defined for square matrices.");

    // Copy matrix to a temporary 2D vector
    vector<vector<double>> temp = matrix;
    double det = 1.0;
    int sign = 1;

    for (int col = 0; col < rows; col++) {
        // Find pivot row
        int pivotRow = -1;
        double maxVal = 0.0;
        for (int row = col; row < rows; row++) {
            if (abs(temp[row][col]) > maxVal) {
                maxVal = abs(temp[row][col]);
                pivotRow = row;
            }
        }
        if (pivotRow == -1 || maxVal == 0.0)
            return 0.0;   // singular matrix

        // Swap rows if needed
        if (pivotRow != col) {
            swap(temp[col], temp[pivotRow]);
            sign *= -1;   // row swap flips sign of determinant
        }

        det *= temp[col][col];

        // Eliminate below
        for (int row = col + 1; row < rows; row++) {
            double factor = temp[row][col] / temp[col][col];
            for (int j = col; j < rows; j++)
                temp[row][j] -= factor * temp[col][j];
        }
    }

    return sign * det;
}

Matrix Matrix::Inverse(){
    if (!isSquare())
        throw logic_error("Inverse is only defined for square matrices.");

    double det = Determinant();
    if (det == 0.0)
        throw logic_error("Matrix is singular, inverse does not exist.");

    int n = rows;

    // Build augmented matrix [A | I]
    vector<vector<double>> aug(n, vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            aug[i][j] = matrix[i][j];
        aug[i][i + n] = 1.0;   // identity on the right
    }

    // Forward elimination with partial pivoting
    for (int col = 0; col < n; col++) {
        // Find pivot
        int pivotRow = col;
        for (int row = col + 1; row < n; row++)
            if (abs(aug[row][col]) > abs(aug[pivotRow][col]))
                pivotRow = row;

        if (abs(aug[pivotRow][col]) < 1e-12)
            throw logic_error("Matrix is singular, inverse does not exist.");

        swap(aug[col], aug[pivotRow]);

        // Scale pivot row
        double pivot = aug[col][col];
        for (int j = 0; j < 2 * n; j++)
            aug[col][j] /= pivot;

        // Eliminate all other rows
        for (int row = 0; row < n; row++) {
            if (row == col) continue;
            double factor = aug[row][col];
            for (int j = 0; j < 2 * n; j++)
                aug[row][j] -= factor * aug[col][j];
        }
    }

    // Extract right half as the inverse
    Matrix result(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result.matrix[i][j] = aug[i][j + n];

    return result;
}