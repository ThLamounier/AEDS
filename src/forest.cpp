#include "forest.hpp"
#include "config.hpp"
#include <fstream>

Forest::Forest() : rows(5), cols(5) {
    grid.resize(rows, std::vector<int>(cols, ARVORE));
}

void Forest::load(const char* filename) {
    std::ifstream file(filename);
    file >> rows >> cols;
    grid.resize(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            file >> grid[i][j];
    file.close();
}

void Forest::save(std::ofstream& out) {
    for (const auto& row : grid) {
        for (auto cell : row)
            out << cell << ' ';
        out << '\n';
    }
}

void Forest::propagate_fire() {
    auto temp = grid;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (grid[i][j] == FOGO) {
                if (i > 0 && grid[i-1][j] == ARVORE) temp[i-1][j] = FOGO;
                if (i < rows-1 && grid[i+1][j] == ARVORE) temp[i+1][j] = FOGO;
                if (j > 0 && grid[i][j-1] == ARVORE) temp[i][j-1] = FOGO;
                if (j < cols-1 && grid[i][j+1] == ARVORE) temp[i][j+1] = FOGO;
                temp[i][j] = QUEIMADA;
            }
    grid = temp;
}
