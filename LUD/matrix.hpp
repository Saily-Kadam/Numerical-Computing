#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdexcept>
using namespace std;

class Matrix {
protected:
    vector<vector<double>> matrix;
    int rows, cols;

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(string filename);
    void takeInputFromUser();

    Matrix operator+(const Matrix& other) ;
    Matrix operator-(const Matrix& other) ;
    Matrix operator*(const Matrix& other);
    Matrix operator/(const Matrix& other);

    void print();
    void writeToFile(string outputFile, string label);
};

class GaussianElimination : public Matrix {
public:
    GaussianElimination(string leftFile, string rightFile);
    virtual void solve(string outputFile) = 0;
};

class WithoutPivoting : public GaussianElimination {
public:
    WithoutPivoting(string leftFile, string rightFile);
    void solve(string outputFile) override;
};

class Pivoting : public GaussianElimination {
public:
    Pivoting(string leftFile, string rightFile);
    void solve(string outputFile) override;
};



class LUDecomposition : public Matrix {
protected:
    vector<vector<double>> L, U;
    int n;
public:
    LUDecomposition(string filename);
    virtual void decompose(string outputFile) = 0;
};

class Doolittle : public LUDecomposition {
public:
    Doolittle(string filename);
    void decompose(string outputFile) override;
};

class Crout : public LUDecomposition {
public:
    Crout(string filename);
    void decompose(string outputFile) override;
};

class Cholesky : public LUDecomposition {
public:
    Cholesky(string filename);
    void decompose(string outputFile) override;
};
