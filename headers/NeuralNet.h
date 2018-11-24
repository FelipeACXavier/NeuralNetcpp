#pragma once
#ifndef NeuralNet_H
#define NeuralNet_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Neuron.h"
#include "Matrix.h"

class NeuralNet
{
	public:
		// Constructor
		NeuralNet(std::vector<int> &layers);
		void createWeights(std::vector<int> &layers);

		// Print methods
		void printNet();
		void printOuput();
		void printWeights();

		// Learning methods
		void feedForward(const std::vector<double> &inputValues);
		void backPropagation(const std::vector<double> &targets);
		void updateWeights(Matrix weights, Matrix derivative, int l);
		void train(std::vector<double> inputs, std::vector<double> targets);

		// Multi-use methods
		void setBias(double x);
		void setActivation(char v);
		void setLearningRate(double x);
		double getInputNum();
		void setInput(const std::vector<double> &inputValues);
		std::vector<double> getOutput();

		// Dealing with files
		void saveNet(std::string filename);
		void loadBias(std::vector<double> myVector);
		static NeuralNet loadNet(std::string filename);
		static std::vector<std::vector<std::vector<double>>> loadInputs(std::string filename, int howMany);


	private:
		int netSize;
		char activeFunc = 's';
		double bias = 0.01;
		double learningRate = 0.5;

		std::vector<int> layerSize;
		std::vector<Matrix> weights;
		std::vector< std::vector<Neuron> > neuralnet; // neuralnet[layerNum][neuronNum]

};

#endif