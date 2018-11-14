#include "Matrix.h"

// --------------------------------------------------------------- //
// ------------------------- Constructor ------------------------- //
// --------------------------------------------------------------- //

// Constructor to initialize with random values
Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->columns = cols;

	for (int i = 0; i < this->rows; i++)
	{
		matrix.push_back(std::vector<double>());
		for (int j = 0; j < this->columns; j++)
		{
			double ran = Neuron::randomize(0, 1);
			matrix.back().push_back(ran);
			//std::cout << "col: " << j << " row: " << i << " value: " << ran << std::endl;
		}
	}
}

// Initializes a zero matrix
Matrix::Matrix(int rows, int cols, int zero)
{
	this->rows = rows;
	this->columns = cols;
	for (int i = 0; i < rows; i++)
	{
		matrix.push_back(std::vector<double>());
		for (int j = 0; j < cols; j++)
		{
			matrix.back().push_back(0);
		}
	}
}

// --------------------------------------------------------------- //
// ------------------------ Other Methods ------------------------ //
// --------------------------------------------------------------- //

// Returns a matrix which is the transpose of the matrix which called the function
Matrix Matrix::transpose()
{
	Matrix* a = new Matrix(this->columns, this->rows);
	for(int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			a->matrix[j][i] = this->matrix[i][j];
		}
	}
	return *a;
}

// Used to print matrix which calls the function matrix.print()
void Matrix::print()
{
	setCoutPrecision(3);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			std::cout << this->matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Return number of rows in matrix
int Matrix::getRows()
{
	return this->rows;
}

// Return number of columns in matrix
int Matrix::getColumns()
{
	return this->columns;
}

// --------------------------------------------------------------- //
// -------------------------- Overloads -------------------------- //
// --------------------------------------------------------------- //

// Overwrites * so it can be used for matrix with vector multiplication
Matrix Matrix::operator * (std::vector<double> &mat)
{
	// Temporary matrix used to store the values
	Matrix temp = Matrix(this->getRows(), 1, 0);

	// Loop through rows of matrix
	for (int i = 0; i < this->getRows(); i++)
	{
		// Loop through each clumns so it can be multiplied by vector values and added later
		for (int j = 0; j < this->getColumns(); j++)
		{
			temp.matrix[i][0] += this->matrix[i][j] * mat[j];
		}
	}
	return temp;
}

// Overwrites * so it can be used for matrix with Neuron multiplication
Matrix Matrix::operator * (std::vector<Neuron> &mat)
{
	// Temporary matrix used to store the values
	Matrix temp = Matrix(this->getRows(), 1, 0);

	// Loop through rows of matrix
	for (int i = 0; i < this->getRows(); i++)
	{
		// Loop through each clumns so it can be multiplied by vector values and added later
		for (int j = 0; j < this->getColumns(); j++)
		{
			temp.matrix[i][0] += this->matrix[i][j] * mat[j].getValue();
		}
	}
	return temp;
}

// Overwrites * so it can be used for matrix with matrix multiplication
Matrix Matrix::operator * (Matrix &mat)
{
	Matrix temp = Matrix(this->getRows(), mat.getColumns(), 0);

	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < mat.getColumns(); j++)
		{
			for (int k = 0; k < this->getColumns(); k++)
			{
				temp.matrix[i][j] += this->matrix[i][k] * mat.matrix[k][j];
			}
		}
	}
	return temp;
}

// Overwrites * so it can be used for matrix with matrix multiplication
Matrix Matrix::operator * (double x)
{
	Matrix temp = Matrix(this->getRows(), this->getColumns(), 0);

	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getColumns(); j++)
		{
			temp.matrix[i][j] += this->matrix[i][j] * x;
		}
	}
	return temp;
}

void Matrix::setCoutPrecision(int x)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(x);
}