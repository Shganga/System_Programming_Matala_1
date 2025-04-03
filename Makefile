#yanivg1000@gmail.com
# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++17 -I./src  # Include the src directory

# Directories
SRC_DIR = src
TEST_DIR = tests

# Source files (from the src folder), exclude main.cpp for tests
SRC = $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Edge.cpp $(SRC_DIR)/Node.cpp $(SRC_DIR)/Algorithms.cpp $(SRC_DIR)/UnionFind.cpp $(SRC_DIR)/PriorityQueue.cpp $(SRC_DIR)/Stack.cpp
OBJ = $(SRC:.cpp=.o)  # Object files for source code

# Test files (from the tests folder)
TEST_SRC = $(TEST_DIR)/Test_graph.cpp $(TEST_DIR)/Test_edge.cpp $(TEST_DIR)/Test_algorithms.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)  # Object files for tests

# Executable names
TARGET = main
TEST_TARGET = test  # For running tests

# Default target (build the main program)
all: $(TARGET)

# Build the main executable (includes main.cpp)
Main: $(OBJ) $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(SRC_DIR)/main.cpp

# Run the main executable
run: Main
	./$(TARGET)

# Test target (compile only the necessary object files and build the test executable)
test: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ)

# Run the test executable
run_test: test
	./$(TEST_TARGET)

# Run Valgrind memory check on the main executable
valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
