#pragma once
#ifndef Matrix_H
#define Matrix_H

#include <vector>
#include <iomanip>
#include "Neuron.h"

class Matrix
{
	public:
		// Constructors
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, int zero);

		// General methods
		int getRows();
		int getColumns();
		Matrix transpose();
		void print();
		Matrix haddamart(Matrix myMatrix);
		static void setCoutPrecision(int x);
		std::vector<std::vector<double>> matrix;
		
		// Overloads
		Matrix operator * (Matrix &mat);
		Matrix operator * (double x);
		Matrix operator * (std::vector<double> &mat);
		Matrix operator * (std::vector<Neuron> &mat);

	private:
		int rows;
		int columns;

};

#endif // !Matrix_H