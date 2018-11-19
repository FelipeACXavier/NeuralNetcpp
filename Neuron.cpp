#include "Neuron.h"

Neuron::Neuron()
{
	this->bias = randomize(0, 1);
	this->currentValue = 0;//randomize(0, 1);
	this->error = 0;
}
double Neuron::getValue()
{
	return this->currentValue;
}
void Neuron::setValue(double x)
{
	this->currentValue = sigmoid(x + this->bias);
}
void Neuron::print(double target)
{
	std::cout << "Value: " << this->currentValue << std::endl;
	std::cout << "Target: " << target << std::endl;
	std::cout << "Error: " << this->error << std::endl;
	std::cout << "Gradient: " << this->Gradient << std::endl << std::endl;
}
void Neuron::setInput(double x)
{
	this->currentValue = x;
}
void Neuron::setError(double x, int i)
{
	if (i == 0)
		this->error = x - this->currentValue;
	else
		this->error = x;
}
double Neuron::getError()
{
	return this->error;
}
double Neuron::sigmoid(double x)
{
	// return tanh(x);
	return 1 / (1 + exp(-x));;
}

double Neuron::dsigmoid(double x)
{
	// return sigmoid(x)*(1 + sigmoid(x));
	// return 1 - (x*x);//x*(1 + x);
	return x*(1 + x);
}

// Calculates the gradient of the neuron which will 
// be used in backpropagation
double Neuron::gradient(double rate)
{
	this->Gradient = rate * this->error * dsigmoid(this->currentValue);
	this->bias = bias + this->Gradient;
	return this->Gradient;
}

// Returns random double to be used for matrix initialization
double Neuron::randomize(int lower_bound, int upper_bound)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(lower_bound, upper_bound);
	return dis(gen);
}
