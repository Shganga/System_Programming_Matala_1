//yanivg1000@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace graph {  // Assuming Graph is in the graph namespace
    class Graph;  // Forward declaration to avoid circular dependencies
}

class Algorithms {
    public:
        static const int INF; // Define constant for infinity

        static graph::Graph dijkstra(const graph::Graph& graph, int start);

        static graph::Graph bfs(const graph::Graph& graph, int start);

        static graph::Graph dfs(const graph::Graph& graph, int start);

        static graph::Graph kruskal(const graph::Graph& graph);

        static graph::Graph prim(const graph::Graph& graph);
};

#endif // ALGORITHMS_HPP
