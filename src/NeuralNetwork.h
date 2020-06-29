#ifndef NEURAL_NETWORK_NEURALNETWORK_H
#define NEURAL_NETWORK_NEURALNETWORK_H

#include <vector>
#include "Perceptron.h"
#include "dataframe.h"

typedef std::vector<Perceptron> layer;

class NeuralNetwork {
    layer input_layer;
    std::vector<layer> hidden_layers;
    Perceptron output_layer;
    t_type output;
    int n_features;

public:
    NeuralNetwork();
    explicit NeuralNetwork(int _n_features);
    void fit(const dataframe& df, int);
    void add_hidden_layer(int n_perceptrons);
    t_type predict(const std::vector<t_type>& sample);

    void init(int n_features);
};


#endif //NEURAL_NETWORK_NEURALNETWORK_H
