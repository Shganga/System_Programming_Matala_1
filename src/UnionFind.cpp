// yanivg1000@gmail.com
#include "UnionFind.hpp"

// Constructor to initialize the UnionFind structure with a given size.
UnionFind::UnionFind(int size) : size(size) {
    parent = new int[size];
    rank = new int[size];
    for (int i = 0; i < size; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Destructor to free dynamically allocated memory.
UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

// Function to find the root of a given element with path compression.
int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Function to union two sets by rank.
void UnionFind::union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}
