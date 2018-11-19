#include "NeuralNet.h"

// --------------------------------------------------------------- //
// ------------------------- Constructor ------------------------- //
// --------------------------------------------------------------- //

// Creates neural network
NeuralNet::NeuralNet(std::vector<int> &layers)
{
	this->layerSize = layers;
	this->netSize = layers.size() - 1;

	for (int i = 0; i < this->layerSize.size(); i++)
	{
		this->neuralnet.push_back(std::vector<Neuron>());
		for (int j = 0; j < this->layerSize[i]; j++)
		{
			this->neuralnet.back().push_back(Neuron());
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
		this->neuralnet[0][i].setBias(this->bias);
		this->neuralnet[0][i].setInput(inputValues[i]);
	}
}

// Returns output of calculations
std::vector<double> NeuralNet::getOutput()
{
	std::vector<double> results;
	for (Neuron &n : this->neuralnet.back())
	{
		results.push_back(n.getValue());
	}
	return results;
}

void NeuralNet::setBias(double x)
{
	this->bias = x;
}
// Executes the feedforward propagation
void NeuralNet::feedForward(const std::vector<double> &inputValues)
{
	// Set net input
	setInput(inputValues);

	// Loops through each layer of net
	for (int i = 0; i < this->netSize; i++)
	{
		std::vector<double> temp;
		temp = (weights[i] * this->neuralnet[i]).toVector();
		// Update the values on the neurons
		int j = 0;
		for(Neuron &n : this->neuralnet[i + 1])
		{
			n.setValue(temp[j], this->activeFunc);
			j++;
		}
	}
}

// Executes the back propagation 
// learning rate * error x dsigmoid * input^T
void NeuralNet::backPropagation(const std::vector<double> &targets)
{
	std::vector<double> errorVector;
	std::vector<double> dsig;
	
	// Loop through every layer of the net
	for(int i = 0; i < this->netSize; i++)
	{
		// Calculates the error for each layer/neuron
		if(i == 0) {
			// Output errors are passed to the function itself
			errorVector = targets;
		} else {
			// Hidden errors are calculating using the weights and errors from previous layers
			errorVector = (this->weights[this->netSize-i].transpose() * errorVector).toVector();
		}
		// Calculates the error and therefore the gradient for each neuron
		int j = 0;
		for(Neuron &n : this->neuralnet[this->netSize-i])
		{
			// Target - current value for each neuron
			n.setError(errorVector[j], i);

			// Learning rate * Error * derivative of activation function
			dsig.push_back(n.gradient(this->learningRate));
			/* if(i == 0)
			{
				std::cout << "\nNeuron: " << j << std::endl;
				n.print(errorVector[j]);
			} */
			// Update errorVector value for hidden layers
			errorVector[j] = n.getError();
			j++;
		}
		// Calculate the derivative weight matrix
		Matrix dsigMat = Matrix::toMatrix(dsig);
		Matrix layerMat = Matrix::toMatrix(this->neuralnet[this->netSize-1-i]).transpose();
		Matrix temp = (dsigMat * layerMat);

		// Update weights based on calculations
		updateWeights(this->weights[this->netSize-1-i], temp, this->netSize-1-i);

		// Reset dsig vector
		dsig.clear();
	}

}

// Initializes the weights with random values
void NeuralNet::createWeights(std::vector<int> &layers)
{
	for (int i = 0; i < this->netSize; i++)
	{		
		// Rows are equal to the output layer
		// Columns are equal to the input layer
		weights.push_back(Matrix(layers[i+1], layers[i]));
	}
	std::cout << "weights length: " << weights.size() << std::endl;
}

// Print current state of network neurons
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

// Print weights of neural network	
void NeuralNet::printWeights()
{
	for (int i = 0; i < this->layerSize.size() - 1; i++)
	{	
		std::cout << "Weight layer: " << i << std::endl;	
		this->weights[i].print();
	}
}

// Sets the wanted learning rate
void NeuralNet::setLearningRate(double x)
{
	this->learningRate = x;
}

// Updates weight values based on the gradient descent for each neuron
void NeuralNet::updateWeights(Matrix weights, Matrix derivative, int l)
{	
	this->weights[l] = weights + derivative;
}

// Train the network
void NeuralNet::train(std::vector<double> inputs, std::vector<double> targets)
{
	this->feedForward(inputs);
	this->backPropagation(targets);
}

// Set which activatios function will be used by the network
// currently the options are sigmoid or hyperbolic tangent
void NeuralNet::setActivation(char v)
{
	this->activeFunc = v;
}