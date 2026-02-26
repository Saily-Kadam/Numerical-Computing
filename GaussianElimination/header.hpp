#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdexcept>
using namespace std;

class GaussianElimination{
    protected:
    vector<vector<double>> matrix;
    int rows, cols;
    public:
    GaussianElimination(string leftFile, string rightFile);
    virtual void solve(string outputFile) = 0;
};

class WithoutPivoting : public GaussianElimination{
    public:
    WithoutPivoting(string leftFile, string rightFile);
    void solve(string outputFile) override;
};

class Pivoting : public GaussianElimination{
    public:
    Pivoting(string leftFile, string rightFile);
    void solve(string outputFile) override;
};