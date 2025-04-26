#include "animal.hpp"
#include "config.hpp"
#include <algorithm>

Animal::Animal(int start_x, int start_y) : x(start_x), y(start_y), alive(true), passos(0), entrou_na_agua(0) {
    std::random_device rd;
    rng.seed(rd());
}

bool Animal::move(std::vector<std::vector<int>>& grid, std::ofstream& out) {
    std::vector<std::pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    std::shuffle(dirs.begin(), dirs.end(), rng);

    out << "Animal na posicao: (" << x << "," << y << ")\n";

    for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < static_cast<int>(grid.size()) && ny >= 0 && ny < static_cast<int>(grid[0].size())) {
            if (grid[nx][ny] == VAZIO || grid[nx][ny] == ARVORE || grid[nx][ny] == AGUA) {
                if (grid[nx][ny] == AGUA) {
                    out << "Animal entrou na agua!\n";
                    entrou_na_agua++;
                }
                grid[x][y] = VAZIO;
                x = nx; y = ny;
                grid[x][y] = ANIMAL;
                passos++;
                return true;
            }
        }
    }

    alive = false;
    out << "Animal nao conseguiu se mover.\n";
    return false;
}
