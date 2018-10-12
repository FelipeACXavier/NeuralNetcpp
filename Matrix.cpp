# include "Matrix.h"

// Class constructor
Matrix::Matrix(int numRows, int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
    
    srand((unsigned) time(NULL));
    
    for (int i = 0; i < this->numRows; i++)
    {   
        std::vector<double> column;

        for(int j = 0; j < this->numCols; j++)
        {              
            column.push_back(this->setRandom(0,1));
        }
        this->values.push_back(column);
    }

}
// Defines the value at an especific position in the matrix
void Matrix::setValue(int row, int column, double value)
{
    this->values.at(row).at(column) = value;
}
// Returns the values of a specific position in the matrix
double Matrix::getValue(int row, int column)
{
    return this->values.at(row).at(column);
}
// Returns the transpose of a matrix
Matrix *Matrix::transpose()
{
    Matrix *tramp = new Matrix(this->numCols, this->numRows);
    for (int i = 0; i < this->numRows; i++)
    {      
        for(int j = 0; j < this->numCols; j++)
        {   
            tramp->setValue(j, i, this->getValue(i,j));
        }
    }
    return tramp;
}
// Prints the current matrix in the console
void Matrix::printMatrix()
{
    for (int i = 0; i < this->numRows; i++)
    {      
        for(int j = 0; j < this->numCols; j++)
        {   
            std::cout<< this->values.at(i).at(j) << "\t\t";
        }
        std::cout<<std::endl;
    }
}
// Generates random doubles to populate the matrix
double Matrix::setRandom(double a, double b)
{
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_real_distribution<> dis(a,b);

    return dis(gen);
}