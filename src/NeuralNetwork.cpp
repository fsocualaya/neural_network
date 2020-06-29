#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork() {
    output = 0;
}

void NeuralNetwork::init(int _n_features){
    output = 0;
    n_features = _n_features;
    input_layer.resize(n_features);
    for(auto&i_perceptron:input_layer)
        i_perceptron.init(n_features);
}

NeuralNetwork::NeuralNetwork(int _n_features) {
    init(_n_features);
}

void NeuralNetwork::add_hidden_layer(int n_perceptrons) {
    layer h_layer(n_perceptrons);

    // Init the perceptrons in the layer
    for (auto &perceptron:h_layer){
        if(hidden_layers.empty())
            perceptron.init(n_features);
        else
            perceptron.init(hidden_layers[hidden_layers.size()-1].size());
    }

    hidden_layers.push_back(h_layer);
}

void NeuralNetwork::fit(const dataframe& df, int epochs) {
    if(!n_features)
        init(df.table[0].size()-1);

    // Iterating epochs
    for(int epoch=0;epoch<epochs;++epoch) {
        // Iterating over rows
        for(int row_idx=0; row_idx < df.table.size();++row_idx){

            std::vector<t_type > X(df.table[row_idx].begin(), df.table[row_idx].end()-1);
            float Y = df.table[row_idx][n_features];

            // Set parameters for the input layer
            for(auto&i_perceptron:input_layer){
                i_perceptron.set_X(X);
                i_perceptron.predict();
                i_perceptron.adjust_weights(Y);
            }

            // Set parameters for the hidden layers
            for(int idx_layer = 0;idx_layer < hidden_layers.size();++idx_layer){
                for(auto&h_perceptron:hidden_layers[idx_layer]){
                    if(idx_layer == 0)
                        h_perceptron.set_percep_X(input_layer);
                    else
                        h_perceptron.set_percep_X(hidden_layers[idx_layer-1]);
                    h_perceptron.predict();
                    h_perceptron.adjust_weights(Y);
                }
            }
        }
    }
}

t_type NeuralNetwork::predict(const std::vector<t_type>& record) {
    if(hidden_layers.empty()){
        output_layer.set_percep_X(input_layer);
    }else{
        output_layer.set_percep_X(hidden_layers[hidden_layers.size()-1]);
    }
    for(int i=0;i<record.size();++i)
        output += output_layer.weights[i]
    output = output_layer.predict();
    return output;
}

