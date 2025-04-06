### yanivg1000@gmail.com

# Graph Algorithms

This project implements several classic graph algorithms in C++, including Dijkstra's, BFS, DFS, Kruskal's, and Prim's algorithms. These algorithms are applied on a custom graph implementation, and helper data structures like Union-Find, Priority Queue, and Stack are also included.

## Overview

This project provides an implementation of various graph algorithms to manipulate and analyze graphs. Each algorithm aims to either find the shortest path, explore the graph, or find the minimum spanning tree (MST) of a given graph. The algorithms work with a custom graph structure that supports vertices, edges, and adjacency lists.

## Algorithms

### Dijkstra's Algorithm

Dijkstra's algorithm is used to find the shortest paths from a starting vertex to all other vertices in a weighted graph. The algorithm uses a priority queue to always select the vertex with the minimum distance.

### Breadth-First Search (BFS)

BFS explores a graph layer by layer, visiting all neighbors of a vertex before moving on to the next level of neighbors. It's often used to find the shortest path in an unweighted graph.

### Depth-First Search (DFS)

DFS explores a graph by diving as deep as possible before backtracking. It is implemented using a stack to simulate the recursive nature of the algorithm.

### Kruskal's Algorithm

Kruskal's algorithm finds the Minimum Spanning Tree (MST) of a graph. It sorts the edges of the graph by weight and then adds edges to the MST using a Union-Find structure to avoid cycles.

### Prim's Algorithm

Prim's algorithm also finds the Minimum Spanning Tree (MST), but it starts from an arbitrary vertex and grows the MST by adding the smallest edge that connects the tree to a new vertex.

## Data Structures

### UnionFind

UnionFind is a data structure used to efficiently find and union disjoint sets, crucial for algorithms like Kruskal's that need to detect cycles in graphs.

### PriorityQueue

A priority queue is implemented using a simple array and supports enqueueing, dequeuing, and decreasing the priority of elements. It is used in Dijkstra's and Prim's algorithms for efficient selection of the next vertex.

### Stack

The Stack is a basic stack implementation that supports push, pop, peek, and checking whether the stack is empty. It is used in DFS for simulating recursion.

## Compiling & Running

### Prerequisites

Make sure you have the following software installed:

- A C++ compiler (`clang++` recommended you can change it to `g++` it will also work)
- CMake (for building the project)

### Build Instructions

To compile the project, follow these steps:

clone the code into your maching: https://github.com/Shganga/System_Programming_Matala_1.git

write `make Main` in the terminal to compile the main file with all the other needed file and `./main` to run it.

write `make test` in the terminal to compile all the tests and files needed to run them after that type `./test` to run the tests.

write `make valgrind` in the terminal to check if there are any leaks in memory.

write `make clean` in the terminal to clean all the compiled files.
