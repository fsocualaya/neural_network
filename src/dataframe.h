#ifndef NEURAL_NETWORK_DATAFRAME_H
#define NEURAL_NETWORK_DATAFRAME_H

#include <vector>
#include <fstream>
#include <sstream>

struct dataframe {
    std::vector<std::vector<double>> table;

    void read_csv(const std::string& filename, bool);

    void print();
};


#endif //NEURAL_NETWORK_DATAFRAME_H
