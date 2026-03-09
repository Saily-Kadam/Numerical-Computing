#include "matrix.hpp"

LUDecomposition::LUDecomposition(string filename) : Matrix(filename) {
    if (rows != cols)
        throw runtime_error("LU Decomposition requires a square matrix! Got " +
            to_string(rows) + "x" + to_string(cols));
    n = rows;
    L.assign(n, vector<double>(n, 0.0));
    U.assign(n, vector<double>(n, 0.0));
}