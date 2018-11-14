#include "NeuralNet.h"
#include "Neuron.h"
#include "Matrix.h"
#include <iostream>

int main()
{
    //std::vector<int> a;a.push_back(2);a.push_back(2);a.push_back(2);
    //NeuralNet net(a);

    Matrix *mat = new Matrix(2,3);
    mat->printMatrix();
    
    std::cout << "---------------" << std::endl;

    Matrix *tmat = mat->transpose();
    tmat->printMatrix();

    Neuron n(1);
    n.setActivation('t');
    std::cout << "t:" << n.activationFunction(0.5) << std::endl;
    std::cout << "dt:" << n.derivativeFunction(0.5) << std::endl;
    
    n.setActivation('s');
    std::cout << "s:" << n.activationFunction(0.5) << std::endl;
    std::cout << "ds:" << n.derivativeFunction(0.5) << std::endl;
    
    return 0;
}