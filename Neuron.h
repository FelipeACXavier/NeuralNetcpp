#pragma once
#ifndef Neuron_H
#define Neuron_H

#include <iostream>
#include <math.h>
#include <random>

class Neuron
{
	public:
		Neuron();
		void setValue(double x, char v);
		void setInput(double x);
		void setBias(double x);
		double getValue();
		double activation(double x, char v);
		double dactivation(double x);
		void setError(double x, int i);
		void print(double target);
		double gradient(double rate);
		double getError();
		static double randomize(int lower_bound, int upper_bound);

	private:
		double bias;
		double currentValue;
		double error;
		double Gradient;
		char activate;
};

#endif