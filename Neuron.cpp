#include "Neuron.h"

Neuron::Neuron(double x)
{
    double a = this->activationFunction(x);
    this->type = 's';
}

double Neuron::activationFunction(double x)
{
    if (this->type == 's')
    {
        return 1/(1 + exp(-x));
    }
    else if (this->type == 'h')
    {
        return tanh(x);
    }
}

void Neuron::setActivation(char type)
{
    this->type = type;
}

double Neuron::derivativeActivation(double x)
{
    return x*(1 - x);
}

