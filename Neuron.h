#ifndef Neuron_H
#define Neuron_H

#include <iostream>
#include <math.h>

class Neuron
{
    public:
        Neuron(double x);
        double activationFunction(double x);
        double derivativeActivation(double x);
        void setActivation(char type);

    private:
        double output;
        double activeValue;
        char type;
};

#endif