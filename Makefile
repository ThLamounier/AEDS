CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: simulador

simulador: src/main.cpp src/forest.cpp src/animal.cpp
	$(CXX) $(CXXFLAGS) -o simulador src/main.cpp src/forest.cpp src/animal.cpp

clean:
	rm -f simulador
