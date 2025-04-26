#include "forest.hpp"
#include "animal.hpp"
#include <fstream>
#include <iostream>

int main() {
    Forest forest;
    forest.load("input.dat");

    Animal animal(0, 0);
    std::ofstream out("output.dat");

    for (int iter = 0; iter < 10 && animal.alive; ++iter) {
        out << "Iteracao " << iter << ":\n";
        animal.move(forest.grid, out);
        forest.propagate_fire();
        forest.save(out);
        out << "\n";
    }

    out.close();
    std::cout << "Simulacao completa!\n";
    return 0;
}
