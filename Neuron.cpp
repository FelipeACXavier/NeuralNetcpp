#include "Neuron.h"

Neuron::Neuron(double initialValue)
{
	this->bias = randomize(0, 5);
	this->currentValue = bias;
	this->error = 0;
}

double Neuron::getValue()
{
	return this->currentValue;
}

void Neuron::setValue(double x)
{
	this->currentValue = sigmoid(x + bias);
}
void Neuron::setError(double x)
{
	this->error = x - this->currentValue;
}
double Neuron::sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

double Neuron::dsigmoid(double x)
{
	return sigmoid(x)*(1 + sigmoid(x));
}

// Returns random double to be used for matrix initialization
double Neuron::randomize(int lower_bound, int upper_bound)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(lower_bound, upper_bound);
	return dis(gen);
}
