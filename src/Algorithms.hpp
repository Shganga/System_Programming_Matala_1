//yanivg1000@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace graph { 
    class Algorithms {
        public:
            static const int INF; 

            static Graph dijkstra(const Graph& graph, int start);

            static Graph bfs(const Graph& graph, int start);

            static Graph dfs(const Graph& graph, int start);

            static Graph kruskal(const Graph& graph);

            static Graph prim(const Graph& graph);
    };
}
#endif // ALGORITHMS_HPP
