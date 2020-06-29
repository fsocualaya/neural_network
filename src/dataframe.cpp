#include <iostream>
#include "dataframe.h"

void dataframe::read_csv(const std::string &filename, bool ignore_idx = false) {
    std::fstream file(filename, std::ios::in);

    if(!file.is_open()){
        std::cerr<<"A problem occurred while opening the file\n";
        return;
    }

    std::string tmp_line;

    std::string field;

    getline(file, tmp_line);
    std::istringstream iss(tmp_line);

    while(file >> tmp_line) {
        iss.clear();
        iss.str(tmp_line);
        std::vector<double> row;
        int col = 0;
        while(std::getline(iss, field, ',')){
            if(ignore_idx && col != 0)
                row.push_back(stof(field));
            col++;
        }
        table.push_back(row);
    }
    file.close();
}

void dataframe::print() {
    for(auto&i:table) {
        for (auto &j:i)
            std::cout << j << ' ';
        std::cout<<'\n';
    }
}
