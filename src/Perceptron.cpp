#include <iostream>
#include <chrono>
#include "Perceptron.h"

t_type get_random(int min, int max){
    static std::default_random_engine e(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution<> dis(min, max);
    return dis(e);
}

Perceptron::Perceptron(int n) {
    init(n);
}

void Perceptron::init(int n){
    weights.resize(n);
    for(auto&weight:weights)
        weight = get_random(-1, 1);
    output = 0;
    bias = get_random(-1, 1);
}

t_type Perceptron::sum_function() {
    t_type sum = bias;
    int n_features = weights.size();
    for(int i=0; i < n_features;++i){
        sum += weights[i] * X[i];
    }
    return sum;
}

t_type Perceptron::sigmoid(t_type sum) {
    return (t_type)(1 / (1 + std::pow(M_E,sum*-1)));
}

t_type Perceptron::predict() {
    t_type sum = sum_function();
    output = sigmoid(sum);
    return output;
}

void Perceptron::adjust_weights(t_type Y){
    t_type error = Y - output;
    t_type n = gradient(output);
    for(int w_idx = 0; w_idx < weights.size(); ++w_idx)
        weights[w_idx] += n * error * X[w_idx];
    bias += error* n;
}

t_type Perceptron::gradient(t_type y_prob) {
    return y_prob*(1-y_prob);
}

void Perceptron::set_X(std::vector<t_type> _X) {
    this->X = _X;
}

void Perceptron::set_percep_X(const std::vector<Perceptron>& _X) {
    std::vector<t_type> input(_X.size());
    for(auto&perceptron:_X){
        input.push_back(perceptron.output);
    }
    this->X = input;
}
