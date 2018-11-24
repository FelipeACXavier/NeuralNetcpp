cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(NeuralNetcpp)

add_executable(
    neuralnet.out
    Main.cpp
    sources/Matrix.cpp
    sources/NeuralNet.cpp
    sources/Neuron.cpp
)