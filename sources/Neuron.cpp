#include "../headers/Neuron.h"

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

// Set the current value of neuron
void Neuron::setValue(double x, char v)
{
	this->currentValue = activation(x, v);
}

// Set neuron as an input neuron
void Neuron::setInput(double x)
{
	this->currentValue = x + this->bias;
}

// Set the error (target - current value)
void Neuron::setError(double x, int i)
{
	if (i == 0)
		this->error = x - this->currentValue;
	else
		this->error = x;
}

// Set the bias 
void Neuron::setBias(double x)
{
	this->bias = x;
}

// --------------------------------------------------------------- //
// --------------------------- Getters --------------------------- //
// --------------------------------------------------------------- //

// Returns the current value
double Neuron::getValue()
{
	return this->currentValue;
}

// Returns the Error
double Neuron::getError()
{
	return this->error;
}

// Returns the bias
double Neuron::getBias()
{
	return this->bias;
}
// --------------------------------------------------------------- //
// ---------------------- Learning Methods ----------------------- //
// --------------------------------------------------------------- //

// Calcultaes de desired activation function
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
// Calculates the derivative of the desired activation
double Neuron::dactivation(double x)
{
	if(this->activate == 's'){
		return x*(1 + x);
	} else if (this->activate == 't'){
		return 1 - (x*x);
	} else {
		std::cout << "Not a valid activation function\nHas this neuron been activated yet?" << std::endl;
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
// --------------------------------------------------------------- //
// ------------------------ Other Methods ------------------------ //
// --------------------------------------------------------------- //

// Returns random double to be used for matrix initialization
double Neuron::randomize(int lower_bound, int upper_bound)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(lower_bound, upper_bound);
	return dis(gen);
}
// Prints all the data from the neuron
void Neuron::print(double target)
{
	std::cout << "Value: " << this->currentValue << std::endl;
	std::cout << "Target: " << target << std::endl;
	std::cout << "Error: " << this->error << std::endl;
	std::cout << "Gradient: " << this->Gradient << std::endl << std::endl;
}