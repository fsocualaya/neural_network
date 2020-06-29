#ifndef NEURAL_NETWORK_PERCEPTRON_H
#define NEURAL_NETWORK_PERCEPTRON_H

#include <random>
#include <cmath>
#include <iostream>

typedef double t_type;

struct Perceptron {
    std::vector<t_type> weights;
    std::vector<t_type> X;
    t_type output;
    t_type bias;

    Perceptron() = default;
    explicit Perceptron(int n);

    t_type sum_function();
    static t_type sigmoid(t_type sum);
    t_type predict();
    static t_type gradient(t_type);

    void init(int n);

    void set_X(std::vector<t_type > _X);

    void adjust_weights(t_type Y);

    void set_percep_X(const std::vector<Perceptron>& _X);

    void set_weight(std::vector<t_type> w);
};


#endif //NEURAL_NETWORK_PERCEPTRON_H
