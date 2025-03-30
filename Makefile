# Compiler
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

# Source files
SRC = Node.cpp Edge.cpp Graph.cpp main.cpp
OBJ = Node.o Edge.o Graph.o main.o
TARGET = main  # The executable file is 'main'

# Default target (compiles everything)
all: main

# Make Main (compiles everything but doesn't run it)
Main: main

# Build the executable
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o main $(OBJ)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the main executable
run: main
	./main

# Run Valgrind memory check
valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all ./main

# Clean build files
clean:
	rm -f $(OBJ) main
