#include"header.hpp"

GaussianElimination::GaussianElimination(string leftFile, string rightFile){
    ifstream fin(leftFile);
    if(!fin) throw runtime_error("Cannot open file: " + leftFile);

    string line;
    rows = 0;
    cols = 0;

    while(getline(fin, line)){
        rows++;
        if(rows == 1){
            istringstream ss(line);
            double val;
            while(ss >> val) cols++;
        }
    }

    if(rows == 0) throw runtime_error("File is empty: " + leftFile);
    if(rows != cols) throw runtime_error("Left matrix is not square!");  // Fix 1: restored

    fin.close();
    fin.open(leftFile);

    // augmented column 
    matrix.resize(rows, vector<double>(cols + 1));

    for(int i = 0; i < rows; i++){
        getline(fin, line);
        istringstream ss(line);
        for(int j = 0; j < cols; j++){
            ss >> matrix[i][j];
        }
    }
    fin.close();

    // add to last column
    ifstream fright(rightFile);
    if(!fright) throw runtime_error("Cannot open file: " + rightFile);

    int rightRows = 0;
    while(getline(fright, line)){
        istringstream ss(line);
        double val;
        ss >> val;
        matrix[rightRows][cols] = val;
        rightRows++;
    }
    fright.close();

    if(rightRows != rows) throw runtime_error("Left and right files have different number of rows!");

    cols = cols + 1; //augmented column
}

WithoutPivoting::WithoutPivoting(string leftFile, string rightFile) : GaussianElimination(leftFile, rightFile){
}

void WithoutPivoting::solve(string outputFile){
    ofstream fout(outputFile);
    if(!fout) throw runtime_error("Cannot open output file: " + outputFile);

    try{
        // Forward elimination
        for(int i = 0; i < rows; i++){
            if(abs(matrix[i][i]) < 1e-12) throw runtime_error("Zero diagonal element found! Use pivoting instead.");  
            for(int j = i + 1; j < rows; j++){
                double factor = matrix[j][i] / matrix[i][i];
                for(int k = i; k < cols; k++){
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }

        // Back substitution
        vector<double> solution(rows);
        for(int i = rows - 1; i >= 0; i--){
            solution[i] = matrix[i][cols - 1];
            for(int j = i + 1; j < rows; j++){
                solution[i] -= matrix[i][j] * solution[j];
            }
            solution[i] /= matrix[i][i];
        }

        // Write output
        fout << "Solution (Without Pivoting):" << endl;
        for(int i = 0; i < rows; i++){
            fout << "x" << i + 1 << " = " << solution[i] << endl;
        }
    }
    catch(exception& e){
        fout << "Error: " << e.what() << endl;
    }

    fout.close();
}

Pivoting::Pivoting(string leftFile, string rightFile) : GaussianElimination(leftFile, rightFile){
}

void Pivoting::solve(string outputFile){
    ofstream fout(outputFile);
    if(!fout) throw runtime_error("Cannot open output file: " + outputFile);

    try{
        // Forward elimination 
        for(int i = 0; i < rows; i++){
            //row with max element in column
            int maxRow = i;
            for(int k = i + 1; k < rows; k++){
                if(abs(matrix[k][i]) > abs(matrix[maxRow][i])){
                    maxRow = k;
                }
            }
            swap(matrix[i], matrix[maxRow]);

            if(abs(matrix[i][i]) < 1e-12) throw runtime_error("Matrix is singular! No unique solution exists.");  // Fix 2: float comparison

            for(int j = i + 1; j < rows; j++){
                double factor = matrix[j][i] / matrix[i][i];
                for(int k = i; k < cols; k++){
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }

        // Back substitution
        vector<double> solution(rows);
        for(int i = rows - 1; i >= 0; i--){
            solution[i] = matrix[i][cols - 1];
            for(int j = i + 1; j < rows; j++){
                solution[i] -= matrix[i][j] * solution[j];
            }
            solution[i] /= matrix[i][i];
        }

        // for writting
        fout << "Solution (With Pivoting):" << endl;
        for(int i = 0; i < rows; i++){
            fout << "x" << i + 1 << " = " << solution[i] << endl;
        }
    }
    catch(exception& e){
        fout << "Error: " << e.what() << endl;
    }

    fout.close();
}