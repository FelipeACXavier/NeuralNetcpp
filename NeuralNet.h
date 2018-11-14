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
		void printNet();
		void setLearningRate(double x);
		void calculateError(std::vector<Neuron> myLayer, const std::vector<double> &targets);

	private:
		std::vector< std::vector<Neuron> > neuralnet; // neuralnet[layerNum][neuronNum]
		double learningRate = 0.5;
		std::vector<Matrix> weights;
		std::vector<int> layerSize;


};

#endif