#pragma once
#include <vector>
#include <fstream>

class Forest {
public:
    std::vector<std::vector<int>> grid;
    int rows, cols;
    Forest();
    void load(const char* filename);
    void save(std::ofstream& out);
    void propagate_fire();
};
