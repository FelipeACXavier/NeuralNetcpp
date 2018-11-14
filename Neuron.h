#pragma once
#ifndef Neuron_H
#define Neuron_H

#include <iostream>
#include <math.h>
#include <random>

class Neuron
{
	public:
		Neuron(double initialValue);
		void setValue(double x);
		double getValue();
		double sigmoid(double x);
		double dsigmoid(double x);
		void setError(double x);
		static double randomize(int lower_bound, int upper_bound);

	private:
		double bias;
		double currentValue;
		double error;
};

#endif