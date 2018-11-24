#pragma once
#ifndef Neuron_H
#define Neuron_H

#include <iostream>
#include <math.h>
#include <random>

class Neuron
{
	public:
		// Constructor
		Neuron();

		// Setters
		void setBias(double x);
		void setInput(double x);
		void setError(double x, int i);
		void setValue(double x, char v);
		
		// Getters
		double getBias();
		double getError();
		double getValue();

		// Learning methods
		double dactivation(double x);
		double gradient(double rate);
		double activation(double x, char v);

		// Extra methods
		void print(double target);
		static double randomize(int lower_bound, int upper_bound);

	private:
		double bias;
		double currentValue;
		double error;
		double Gradient;
		char activate;
};

#endif