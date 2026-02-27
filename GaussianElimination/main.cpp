#include"header.hpp"

int main(){
    int folderChoice, methodChoice;

    cout << "Select folder:" << endl;
    cout << "1. 49" << endl;
    cout << "2. 225" << endl;
    cin >> folderChoice;

    cout << "Select method:" << endl;
    cout << "1. Without Pivoting" << endl;
    cout << "2. With Pivoting" << endl;
    cin >> methodChoice;

    string leftFile, rightFile, outputFile;

    if(folderChoice == 1){
        leftFile = "49/49l.txt";
        rightFile = "49/49r.txt";
        outputFile = "49/output.txt";
    } else {
        leftFile = "225/225left.txt";
        rightFile = "225/225right.txt";
        outputFile = "225/output.txt";
    }

    try{
        if(methodChoice == 1){
            WithoutPivoting obj(leftFile, rightFile);
            obj.solve(outputFile);
        } else {
            Pivoting obj(leftFile, rightFile);
            obj.solve(outputFile);
        }
        cout << "Solution written to " << outputFile << endl;
    }
    catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}