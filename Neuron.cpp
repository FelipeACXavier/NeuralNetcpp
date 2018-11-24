#include "Neuron.h"

// --------------------------------------------------------------- //
// ------------------------- Constructor ------------------------- //
// --------------------------------------------------------------- //
Neuron::Neuron()
{
	this->bias = randomize(-1, 1);
	// std::cout << "bias: " << this->bias << std::endl;
	this->currentValue = 0;//randomize(0, 1);
	this->error = 0;
}

// --------------------------------------------------------------- //
// --------------------------- Setters --------------------------- //
// --------------------------------------------------------------- //
void Neuron::setValue(double x, char v)
{
	this->currentValue = activation(x, v);
}
void Neuron::setInput(double x)
{
	this->currentValue = x + this->bias;
}
void Neuron::setError(double x, int i)
{
	if (i == 0)
		this->error = x - this->currentValue;
	else
		this->error = x;
}
void Neuron::setBias(double x)
{
	this->bias = x;
}

// --------------------------------------------------------------- //
// --------------------------- Getters --------------------------- //
// --------------------------------------------------------------- //
double Neuron::getValue()
{
	return this->currentValue;
}
double Neuron::getError()
{
	return this->error;
}

// --------------------------------------------------------------- //
// ------------------------ Other Methods ------------------------ //
// --------------------------------------------------------------- //
double Neuron::activation(double x, char v)
{
	this->activate = v;
	if(v == 's'){
		return 1 / (1 + exp(-x));
	} else if (v == 't'){
		return tanh(x);
	} else {
		std::cout << "Not a valid activation function" << std::endl;
		return 0;
	}
}
double Neuron::dactivation(double x)
{
	if(this->activate == 's'){
		return x*(1 + x);
	} else if (this->activate == 't'){
		return 1 - (x*x);
	} else {
		std::cout << "Not a valid activation function\nHas this neuron been actiavted yet?" << std::endl;
		return 0;
	}
}
// Calculates the gradient of the neuron which will 
// be used in backpropagation
double Neuron::gradient(double rate)
{
	this->Gradient = rate * this->error * dactivation(this->currentValue);
	this->bias = this->bias + this->Gradient;
	return this->Gradient;
}
// Returns random double to be used for matrix initialization
double Neuron::randomize(int lower_bound, int upper_bound)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(lower_bound, upper_bound);
	return dis(gen);
}
void Neuron::print(double target)
{
	std::cout << "Value: " << this->currentValue << std::endl;
	std::cout << "Target: " << target << std::endl;
	std::cout << "Error: " << this->error << std::endl;
	std::cout << "Gradient: " << this->Gradient << std::endl << std::endl;
}