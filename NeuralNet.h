#pragma once
#ifndef NeuralNet_H
#define NeuralNet_H

#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Matrix.h"

class NeuralNet
{
	public:
		// Constructor
		NeuralNet(std::vector<int> &layers);

		// Overall usage
		void setInput(const std::vector<double> &inputValues);
		std::vector<double> getOutput();
		void feedForward(const std::vector<double> &inputValues);
		void backPropagation(const std::vector<double> &targets);
		void createWeights(std::vector<int> &layers);
		void setLearningRate(double x);
		void updateWeights(Matrix weights, Matrix derivative, int l);
		void train(std::vector<double> inputs, std::vector<double> targets);
		
		void printNet();
		void printWeights();
		int netSize;

	private:
		std::vector< std::vector<Neuron> > neuralnet; // neuralnet[layerNum][neuronNum]
		double learningRate = 0.5;
		std::vector<Matrix> weights;
		std::vector<int> layerSize;


};

#endif