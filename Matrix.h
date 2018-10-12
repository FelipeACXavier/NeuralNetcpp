#ifndef Matrix_H
#define Matrix_H

#include <iostream>
#include <vector>
#include <random>

class Matrix
{
    public:
        // Constructor for matrix class
        Matrix(int numRows, int numCols);
        // Print Matrix passed as argument
        void printMatrix();
        // Returns a matrix which is the transpose of the argument matrix
        Matrix *transpose();
        // Gives a random number to matrix
        double setRandom(double a, double b);
        void setValue(int row, int column, double value);
        double getValue(int row, int column);

    private:
        int numRows;
        int numCols;

        std::vector< std::vector<double> > values;
};


#endif