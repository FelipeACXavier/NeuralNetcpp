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

// Initializes the weights with random values
void NeuralNet::createWeights(std::vector<int> &layers)
{
	for (int i = 0; i < this->netSize; i++)
	{		
		// Rows are equal to the output layer
		// Columns are equal to the input layer
		weights.push_back(Matrix(layers[i+1], layers[i]));
	}
	// std::cout << "weights length: " << weights.size() << std::endl;
}
// --------------------------------------------------------------- //
// ------------------------ Print Methods ------------------------ //
// --------------------------------------------------------------- //

// Prints just the outputs of the network
void NeuralNet::printOuput()
{
	std::cout << "Output: ";
	for (Neuron &n : this->neuralnet.back())
	{
		std::cout << n.getValue() << ' ';
	}
	std::cout << std::endl;
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

// --------------------------------------------------------------- //
// ---------------------- Learning Methods ----------------------- //
// --------------------------------------------------------------- //

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
// --------------------------------------------------------------- //
// ---------------------- Multi-Use Methods ---------------------- //
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

double NeuralNet::getInputNum()
{
	return this->layerSize[0];
}
// --------------------------- Setters --------------------------- //
// Define bias used to train the network
void NeuralNet::setBias(double x)
{
	this->bias = x;
}

// Sets the wanted learning rate
void NeuralNet::setLearningRate(double x)
{
	this->learningRate = x;
}

// Set which activatios function will be used by the network
// currently the options are sigmoid or hyperbolic tangent
void NeuralNet::setActivation(char v)
{
	this->activeFunc = v;
}
// --------------------- Dealing with files ---------------------- //
// Saves network to file so it can be used later
void NeuralNet::saveNet(std::string filename)
{
	std::ofstream myfile;
	myfile.open(filename);
	// Adds title
	//myfile << filename << "\n\n";
	// Saves network topology ---------------------
	myfile << "Topology:\n";
	for(int i = 0; i < this->layerSize.size(); i++)
		myfile << this->layerSize[i] << ' ';
	myfile << '\n';
	
	// Saves activation function ------------------
	myfile << "Activation function:\n" << this->activeFunc << '\n';
	
	// Saves bias for input -----------------------
	myfile << "Input Bias:\n" << this->bias << "\n";

	// Saves weights ------------------------------
	int counter = 0;
	for(Matrix &m : this->weights)
	{
		myfile << "Weights: " << counter << "\n";
		m.saveMatrix(myfile);
		myfile << '\n';
		counter++;
	}

	// Saves bias ---------------------------------
	myfile << "Bias:\n";
	for (int i = 0; i < this->layerSize.size(); i++)
	{
		for (int j = 0; j < this->layerSize[i]; j++)
		{
			myfile << this->neuralnet[i][j].getBias() << ' ';
		}
	}
	myfile.close();
	std::cout << "Network saved to " << filename << std::endl;
}

// Loads a network from file
NeuralNet NeuralNet::loadNet(std::string filename)
{
	NeuralNet* net;
	Matrix* temp;

	std::vector<int> topology;
	std::vector<double> weights;
	std::vector<double> bias;

	std::string line;
	int rows, cols, whichLine = 0;
	int whichWeight = 0;
	double loadbias;

	std::ifstream myfile;
	myfile.open(filename);

	// Check whether the file is open
	if (myfile.is_open())
	{
		// Go through every line in the saved file
		while (std::getline(myfile,line))
    	{

			if(line[0] == 'T')
				std::cout << "Reading Topology" << std::endl;
			else if(line[0] == 'A')
				std::cout << "\nReading Activation Function" << std::endl;
			else if(line[0] == 'W')
				std::cout << "\nReading Weights" << std::endl;
			else if(line[0] == 'I')
				std::cout << "\nReading Input Bias" << std::endl;
			else if(line[0] == 'B'){
				std::cout << "\nReading Bias" << std::endl;
				whichLine++;
			} else 
			{
				std::stringstream ss(line);
				switch(whichLine)
				{
					// Read the topology of thewsaved neural net --------------------------------
					case 0: 
						int tp;
						while(ss >> tp)
							topology.push_back(tp);
						
						Matrix::printVector(topology);

						net = new NeuralNet(topology);
						whichLine++;
						break;
					// Read the activation function of the saved neural net ---------------------	
					case 1: 
						char c;
						ss >> c;
						net->setActivation(c);
						std::cout << "Activation: " << c << '\n';
						whichLine++;
						break;
					// Read the input bias of the saved neural net ------------------------------
					case 2: 
						ss >> loadbias;
						std::cout << "Bias: " << loadbias << '\n';
						whichLine++;
						break;
					// Read the weights of the saved neural net ---------------------------------
					case 3: 
						rows = topology[whichWeight + 1];
						cols = topology[whichWeight];
						
						double we;
						while(ss >> we)
							weights.push_back(we);
						std::cout << "Read ";	
						Matrix::printVector(weights);
						temp = new Matrix(weights, rows, cols);

						net->weights[whichWeight] = *temp;
						std::cout << "Weight layer " << whichWeight << ":\n";
						net->weights[whichWeight].print();
						
						// Clear vector so it can be populated again
						weights.clear();
						
						whichWeight++;
						break;
					// Read the bias for the whole network ---------------------------------
					case 4: 
						double bi;
						while(ss >> bi)
							bias.push_back(bi);
						
						std::cout << "Read ";
						Matrix::printVector(bias);
						
						net->loadBias(bias);
						net->setBias(loadbias);

						whichLine++;
						break;
					default:
						std::cout << "There was an error loading the network" << std::endl;
						std::cout << "Error i step " << whichLine+1 << std::endl;
				}
			}
	    }
		std::cout << "Network Loaded\n" << std::endl;
		myfile.close();
	} else {
		std::cout << "It was not possible to open the expecified file" << std::endl;
	}	
	return *net;

}

// Used to load the bias from file to network
void NeuralNet::loadBias(std::vector<double> myVector)
{
	int index = 0;
	for (int i = 0; i < this->layerSize.size(); i++)
	{
		for (int j = 0; j < this->layerSize[i]; j++)
		{
			this->neuralnet[i][j].setBias(myVector[index]);
			index++;
		}
	}
}

// Read input and targets from file
// It needs the name of the file and how many inputs the network has
std::vector<std::vector<std::vector<double>>> NeuralNet::loadInputs(std::string filename, int howMany)
{
	std::vector<std::vector<std::vector<double>>> inputs;
	std::string line;
	int index = 0;
	std::ifstream myfile;
	myfile.open(filename);

	// Check whether the file is open
	if (myfile.is_open())
	{
		// Go through every line in the saved file
		while (std::getline(myfile,line))
    	{
			inputs.push_back(std::vector<std::vector<double>>());
			inputs[index].push_back(std::vector<double>());
			inputs[index].push_back(std::vector<double>());

			double in;
			std::stringstream ss(line);
			int x = 0;
			while(ss >> in)
			{
				if(x < howMany)
				{
					inputs[index][0].push_back(in);
				} else {
					inputs[index][1].push_back(in);
				}
				x++;	
			}
			index++;
		}
		myfile.close();
	} else {
		std::cout << "Could not open file " << filename << std::endl;
	}
	return inputs;
}
