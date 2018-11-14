#include "NeuralNet.h"

// --------------------------------------------------------------- //
// ------------------------- Constructor ------------------------- //
// --------------------------------------------------------------- //

// Creates neural network
NeuralNet::NeuralNet(std::vector<int> &layers)
{
	this->layerSize = layers;
	for (int i = 0; i < this->layerSize.size(); i++)
	{
		this->neuralnet.push_back(std::vector<Neuron>());
		for (int j = 0; j < this->layerSize[i]; j++)
		{
			this->neuralnet.back().push_back(Neuron(Neuron::randomize(0,1)));
		}
	}
	createWeights(layers);
}

// --------------------------------------------------------------- //
// ------------------------ Other Methods ------------------------ //
// --------------------------------------------------------------- //

// Gets user input and set as inputs for the neural network
void NeuralNet::setInput(const std::vector<double> &inputValues)
{
	for (int i = 0; i < this->neuralnet[0].size(); i++) 
	{
		this->neuralnet[0][i].setValue(inputValues[i]);
	}
}

// Returns output of calculations
std::vector<double> NeuralNet::getOutput()
{
	std::vector<double> results;
	int i = 0;
	for (Neuron n : this->neuralnet.back())
	{
		results.push_back(n.getValue());
	}
	return results;
}

// Executes the feedforward propagation
void NeuralNet::feedForward(const std::vector<double> &inputValues)
{
	// Set net input
	setInput(inputValues);
	
	// Loops through each layer of net
	for (int i = 0; i < this->layerSize.size() - 1; i++)
	{
		int j = 0;
		Matrix temp = Matrix(this->layerSize[i + 1], 1, 0);
		Matrix tramp = weights[i].transpose();
		
		temp =  tramp * this->neuralnet[i];
		//temp.print(); Uncomment if you want to see the steps

		// Update the values on the neuron
		for (Neuron n : this->neuralnet[i + 1])
		{
			n.setValue(temp.matrix[j][0]);
			j++;
			//std::cout << n.getValue() << " ";
		}
	}
}

// Executes the back propagation 
// learningrate * error x dsigmoid * input^T
void NeuralNet::backPropagation(const std::vector<double> &targets)
{
	for(int i = 0; i < this->layerSize.size() - 1; i++)
	{
		

	}

}

void NeuralNet::calculateError(std::vector<Neuron> myLayer, const std::vector<double> &targets)
{
	int errorCounter = 0;
	for(Neuron n : myLayer)
	{
		n.setError(targets[errorCounter]);
		errorCounter++;
	}
}

// Initializes the weights with random values
void NeuralNet::createWeights(std::vector<int> &layers)
{
	for (int i = 0; i < layers.size() - 1; i++)
	{		
		weights.push_back(Matrix(layers[i], layers[i + 1]));
	}
}

// Print current state of network
void NeuralNet::printNet()
{
	Matrix::setCoutPrecision(3);
	for (int i = 0; i < this->layerSize.size(); i++)
	{
		for (int j = 0; j < this->layerSize[i]; j++)
		{
			std::cout << this->neuralnet[i][j].getValue() << ' ';
		}
		std::cout << std::endl;
	}
}

void NeuralNet::setLearningRate(double x)
{
	this->learningRate = x;
}
