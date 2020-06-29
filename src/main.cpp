
#include "NeuralNetwork.h"

int main() {

    dataframe df;
    df.read_csv("../datasets/iris_reducido_train.csv", true);

    int n_features = df.table[0].size()-1;
    NeuralNetwork nn(n_features);
    nn.add_hidden_layer(3);
    nn.fit(df, 2);
    std::cout<<nn.predict({3.7,1.0});

    return 0;
}
