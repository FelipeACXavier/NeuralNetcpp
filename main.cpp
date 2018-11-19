#include "NeuralNet.h"
#include "Neuron.h"
#include "Matrix.h"
#include <iostream>

int main()
{
    std::vector<std::vector<double>> inputs = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
    };
    std::vector<std::vector<double>> targets = {
        {1},
        {0},
        {0},
        {1},
    };
    std::vector<int> topology = {2, 2, 1};

    NeuralNet mynet = NeuralNet(topology);
    mynet.printNet();
    mynet.setActivation('t');
    mynet.setBias(0.02);
    mynet.setLearningRate(0.8);

    std::srand(std::time(nullptr));

    for(int i = 0; i < 10000; i++)
    {
        std::cout << "Generation " << i << " >>>>>>> " << std::endl;
        int j = std::rand()/((RAND_MAX + 1u)/4);
        mynet.train(inputs[j], targets[j]);
        // mynet.printNet();
    }
    
    mynet.feedForward(inputs[0]);
    std:: cout << "output 0: " << std::endl;
    mynet.printNet();
    std::cout << "----------" << std::endl;

    mynet.feedForward(inputs[1]);
    std:: cout << "output 1: " << std::endl;
    mynet.printNet();
    std::cout << "----------" << std::endl;    

    mynet.feedForward(inputs[2]);
    std:: cout << "output 2: " << std::endl;
    mynet.printNet();
    std::cout << "----------" << std::endl;

    mynet.feedForward(inputs[3]);
    std:: cout << "output 3: " << std::endl;
    mynet.printNet();

    /* Matrix a = Matrix(2, 3);
    Matrix b = Matrix(3, 1);
    std::vector<double> d = {1,1,1};
    Matrix c = a * d;

    a.print();
    Matrix::printVector(d);
    b.print();
    c.print(); */


    
    return 0;
}