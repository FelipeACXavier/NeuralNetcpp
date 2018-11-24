#include "../headers/Matrix.h"

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
// Initializes from vector with own inputs
Matrix::Matrix(std::vector<double> myVector, int rows, int cols)
{
	this->rows = rows;
	this->columns = cols;
	int index = 0;
	for (int i = 0; i < rows; i++)
	{
		matrix.push_back(std::vector<double>());
		for (int j = 0; j < cols; j++)
		{
			matrix.back().push_back(myVector[index]);
			index++;
		}
	}
}
// --------------------------------------------------------------- //
// ------------------------ Print Methods ------------------------ //
// --------------------------------------------------------------- //

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
	std::cout << std::endl;
}
// Print double vectors 
void Matrix::printVector(std::vector<double> &myVector)
{
	Matrix::setCoutPrecision(3);
	std::cout << "Vector: ";
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << myVector[i] << ' ';
	}
	std::cout << std::endl;
}
// Print int vectors 
void Matrix::printVector(std::vector<int> &myVector)
{
	Matrix::setCoutPrecision(3);
	std::cout << "Vector: ";
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << myVector[i] << ' ';
	}
	std::cout << std::endl;
}
// Print Neuron vectors 
void Matrix::printVector(std::vector<Neuron> &myVector)
{
	Matrix::setCoutPrecision(3);
	std::cout << "Vector: ";
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << myVector[i].getValue() << ' ';
	}
	std::cout << std::endl;
}
// --------------------------------------------------------------- //
// ------------------------- Conversions --------------------------//
// --------------------------------------------------------------- //

// Coverts a double vector into a matrix object
Matrix Matrix::toMatrix(std::vector<double> myVector)
{
	Matrix temp = Matrix(myVector.size(), 1, 0);
	for (int i = 0; i < myVector.size(); i++)
	{
		temp.matrix[i][0] = myVector[i];
	}
	return temp;
}

// Coverts a neuron vector into a matrix object
Matrix Matrix::toMatrix(std::vector<Neuron> myVector)
{
	Matrix temp = Matrix(myVector.size(), 1, 0);
	for (int i = 0; i < myVector.size(); i++)
	{
		temp.matrix[i][0] = myVector[i].getValue();
	}
	return temp;
}

// Coverts a int vector into a matrix object
Matrix Matrix::toMatrix(std::vector<int> myVector)
{
	Matrix temp = Matrix(myVector.size(), 1, 0);
	for (int i = 0; i < myVector.size(); i++)
	{
		temp.matrix[i][0] = myVector[i];
	}
	return temp;
}

// Converts matrix to columns vector
std::vector<double> Matrix::toVector()
{
	std::vector<double> temp;
	for (int i = 0; i < this->getRows(); i++)
	{
		temp.push_back(this->matrix[i][0]);
	}
	return temp;
}

// --------------------------------------------------------------- //
// ---------------------- Multi-Use Methods ---------------------- //
// --------------------------------------------------------------- //

// --------------------------- Getters --------------------------- //
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
// ------------------------- Other methods  ---------------------- //
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
// Set how many decimals will be printed 
void Matrix::setCoutPrecision(int x)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(x);
}
// ---------------------- Dealing with files ---------------------- //
// Saves matrix in txt format for further use
void Matrix::saveMatrix(std::ofstream &filename)
{
	//std::cout << "Rows: " << this->getRows() << std::endl;
	//std::cout << "Columns: " << this->getColumns() << std::endl;
	for(int i = 0; i < this->getRows(); i++)
	{
		for(int j = 0; j < this->getColumns(); j++)
		{
			//std::cout << this->matrix[i][j] << ' ';
			filename << this->matrix[i][j] << ' ';
		}
		//std::cout << std::endl;
		//filename << "\n";
	}
}
// --------------------------------------------------------------- //
// -------------------------- Overloads -------------------------- //
// --------------------------------------------------------------- //

// Overwrites * so it can be used for matrix with vector multiplication
Matrix Matrix::operator * (std::vector<double> &mat)
{
	// Temporary matrix used to store the values
	Matrix temp = Matrix(this->getRows(), 1, 0);
	if(this->getColumns() == mat.size())
	{
		// Loop through rows of matrix
		for (int i = 0; i < this->getRows(); i++)
		{
			// Loop through each columns so it can be multiplied by vector values and added later
			for (int j = 0; j < this->getColumns(); j++)
			{
				temp.matrix[i][0] += this->matrix[i][j] * mat[j];
			}
		}
	} else {
		std::cout << "Lenghts dont match double matrix" << std::endl;
	}
	return temp;
}

// Overwrites * so it can be used for matrix with Neuron multiplication
Matrix Matrix::operator * (std::vector<Neuron> &mat)
{
	// Temporary matrix used to store the values
	Matrix temp = Matrix(this->getRows(), 1, 0);
	if(this->getColumns() == mat.size())
	{
		// Loop through rows of matrix
		for (int i = 0; i < this->getRows(); i++)
		{
			// Loop through each clumns so it can be multiplied by vector values and added later
			for (int j = 0; j < this->getColumns(); j++)
			{
				temp.matrix[i][0] += this->matrix[i][j] * mat[j].getValue();
			}
		}
	} else {
		std::cout << "Lenghts dont match Neuron matrix" << std::endl;		
	}
	return temp;
}

// Overwrites * so it can be used for matrix with matrix multiplication
Matrix Matrix::operator * (Matrix &mat)
{
	Matrix temp = Matrix(this->getRows(), mat.getColumns(), 0);
	if (this->getColumns() == mat.getRows())
	{
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
	} else {
		std::cout << "Cannot multiply: " << this->getColumns() << " and " << mat.getRows() << std::endl;
	}
	return temp;
}

// Overwrites - so it can be used for matrix with matrix subtraction
Matrix Matrix::operator - (Matrix &mat)
{
	Matrix temp = Matrix(this->getRows(), mat.getColumns(), 0);
	
	if(this->getRows() == mat.getRows() && this->getColumns() == mat.getColumns())
	{
		for (int i = 0; i < this->getRows(); i++)
		{
			for (int j = 0; j < mat.getColumns(); j++)
			{
					temp.matrix[i][j] += this->matrix[i][j] - mat.matrix[i][j];
			}
		}
	} else {
		std::cout << "Matrix sizes need to be equal" << std::endl;
	}
	return temp;
}

// Overwrites + so it can be used for matrix with matrix addition
Matrix Matrix::operator + (Matrix &mat)
{
	Matrix temp = Matrix(this->getRows(), mat.getColumns(), 0);

	if(this->getRows() == mat.getRows() && this->getColumns() == mat.getColumns())
	{
		for (int i = 0; i < this->getRows(); i++)
		{
			for (int j = 0; j < mat.getColumns(); j++)
			{
					temp.matrix[i][j] += this->matrix[i][j] + mat.matrix[i][j];
			}
		}
	} else {
		std::cout << "Matrix sizes need to be equal" << std::endl;
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

// Overwrites * so it can be used for matrix with matrix division
Matrix Matrix::operator / (Matrix &mat)
{
	Matrix temp = Matrix(this->getRows(), mat.getColumns(), 0);
	Matrix trps = mat.transpose();

	if (this->getColumns() == trps.getRows())
	{
		for (int i = 0; i < this->getRows(); i++)
		{
			for (int j = 0; j < trps.getColumns(); j++)
			{
				for (int k = 0; k < this->getColumns(); k++)
				{
					temp.matrix[i][j] += this->matrix[i][k] * trps.matrix[k][j];
				}
			}
		}
	} else {
		std::cout << "Cannot divide: " << this->getColumns() << " and " << trps.getRows() << std::endl;
	}
	return temp;
}