cmake_minimum_required(VERSION 3.15)
project(neural_network)

set(CMAKE_CXX_STANDARD 14)

add_executable(neural_network
        src/main.cpp
        src/Perceptron.cpp
        src/NeuralNetwork.cpp
        src/dataframe.cpp
        )