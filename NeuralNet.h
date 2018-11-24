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

		// Overall usage
		void setInput(const std::vector<double> &inputValues);
		void feedForward(const std::vector<double> &inputValues);
		void backPropagation(const std::vector<double> &targets);
		void createWeights(std::vector<int> &layers);
		void setLearningRate(double x);
		void updateWeights(Matrix weights, Matrix derivative, int l);
		void train(std::vector<double> inputs, std::vector<double> targets);
		void loadBias(std::vector<double> myVector);
		void setActivation(char v);
		void setBias(double x);
		void printNet();
		void printWeights();

		void saveNet(std::string filename);
		static NeuralNet loadNet(std::string filename);

		std::vector<double> getOutput();

	private:
		double learningRate = 0.5;
		int netSize;
		char activeFunc = 's';
		double bias = 0.01;

		std::vector< std::vector<Neuron> > neuralnet; // neuralnet[layerNum][neuronNum]
		std::vector<Matrix> weights;
		std::vector<int> layerSize;

};

#endif