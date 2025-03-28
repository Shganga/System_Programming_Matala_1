# Compiler
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

# Source files (including main.cpp)
SRC = Node.cpp Edge.cpp Graph.cpp main.cpp
OBJ = Node.o Edge.o Graph.o main.o
TARGET = main  # Executable target

# Default target
all: $(TARGET)

# Build the executable (main.cpp)
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp into object file
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)
