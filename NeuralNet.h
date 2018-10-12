#ifndef NeuralNet_H
#define NeuralNet_H

#include <iostream>
#include <vector>
#include "Neuron.h"

typedef std::vector<Neuron> Layer;

class NeuralNet
{
    public:
        NeuralNet(std::vector<int> &layers);
        void feedForward(const std::vector<float> &inputValues);
        void backPropagation(const std::vector<float> &targets);
        void getResults(std::vector<float> &outputs);
        void printNet(NeuralNet matrix);

    private:
        std::vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
        int numLayers;
        
};

#endif