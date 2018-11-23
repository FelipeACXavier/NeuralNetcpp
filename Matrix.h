#pragma once
#ifndef Matrix_H
#define Matrix_H

#include <vector>
#include <fstream>
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
		
		std::vector<std::vector<double>> matrix;

		Matrix transpose();
		void saveMatrix(ofstream filename);
		void print();
		static void printVector(std::vector<double> &myVector);
		static void printVector(std::vector<Neuron> &myVector);
		static void setCoutPrecision(int x);

		// Convertions
		static Matrix toMatrix(std::vector<double> myVector);
		static Matrix toMatrix(std::vector<Neuron> myVector);
		static Matrix toMatrix(std::vector<int> myVector);
		std::vector<double> toVector();
		
		// Overloads
		Matrix operator * (Matrix &mat);
		Matrix operator * (double x);
		Matrix operator * (std::vector<double> &mat);
		Matrix operator * (std::vector<Neuron> &mat);
		Matrix operator + (Matrix &mat);
		Matrix operator - (Matrix &mat);

	private:
		int rows;
		int columns;

};

#endif // !Matrix_H