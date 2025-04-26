#pragma once
#include <vector>
#include <random>
#include <fstream>

class Animal {
public:
    int x, y;
    bool alive;
    int passos;
    int entrou_na_agua;
    std::mt19937 rng;

    Animal(int start_x, int start_y);
    bool move(std::vector<std::vector<int>>& grid, std::ofstream& out);
};
