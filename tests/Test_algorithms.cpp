#include "doctest.h"
#include "Graph.hpp"
#include "Edge.hpp"
#include "Algorithms.hpp"
#include "UnionFind.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

TEST_CASE("Dijkstra algorithm from vertex 0 (undirected)") {
    graph::Graph g(5);
    g.add_edge(0, 1, 10);
    g.add_edge(1, 2, 30);
    g.add_edge(2, 3, 30);
    g.add_edge(3, 4, 10);
    g.add_edge(0, 4, 100);

    // Directly call the static method using the class name
    graph::Graph spt = Algorithms::dijkstra(g, 0);  // Get the shortest path tree


    // Verify the expected edges in the shortest path tree (undirected graph)
    CHECK(spt.has_edge(0, 1));  // Edge 0 <-> 1 should be present (weight 10)
    CHECK(spt.has_edge(1, 2));  // Edge 1 <-> 2 should be present (weight 30)
    CHECK(spt.has_edge(2, 3));  // Edge 2 <-> 3 should be present (weight 60)

    // Verify that edges not in the shortest path tree do not exist
    CHECK_FALSE(spt.has_edge(0, 4));  // Edge 0 <-> 4 should not be present
}


TEST_CASE("Breadth-First Search (BFS)") {
    graph::Graph g(6);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 20);
    g.add_edge(1, 3, 30);
    g.add_edge(2, 4, 40);
    g.add_edge(3, 5, 50);

    graph::Graph bfs_tree = Algorithms::bfs(g, 0);

    CHECK(bfs_tree.has_edge(0, 1));
    CHECK(bfs_tree.has_edge(0, 2));
    CHECK(bfs_tree.has_edge(1, 3));
    CHECK(bfs_tree.has_edge(2, 4));
    CHECK(bfs_tree.has_edge(3, 5));
}

TEST_CASE("Depth-First Search (DFS)") {
    graph::Graph g(6);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 20);
    g.add_edge(1, 3, 30);
    g.add_edge(2, 4, 40);
    g.add_edge(3, 5, 50);

    graph::Graph dfs_tree = Algorithms::dfs(g, 0);

    CHECK(dfs_tree.has_edge(0, 1));
    CHECK(dfs_tree.has_edge(1, 3));
    CHECK(dfs_tree.has_edge(0, 2));
    CHECK(dfs_tree.has_edge(2, 4));
    CHECK(dfs_tree.has_edge(3, 5));
}

TEST_CASE("Kruskal's algorithm") {
    graph::Graph g(6);
    g.add_edge(0, 1, 10);
    g.add_edge(1, 2, 20);
    g.add_edge(2, 3, 30);
    g.add_edge(3, 4, 40);
    g.add_edge(4, 5, 50);
    g.add_edge(0, 2, 15);
    g.add_edge(1, 3, 25);

    graph::Graph mst = Algorithms::kruskal(g);

    CHECK(mst.has_edge(0, 1));
    CHECK(mst.has_edge(0, 2));
    CHECK(mst.has_edge(1, 3));
    CHECK(mst.has_edge(2, 4));
    CHECK(mst.has_edge(3, 5));
}

TEST_CASE("Prim's algorithm") {
    graph::Graph g(6);
    g.add_edge(0, 1, 10);
    g.add_edge(1, 2, 20);
    g.add_edge(2, 3, 30);
    g.add_edge(3, 4, 40);
    g.add_edge(4, 5, 50);
    g.add_edge(0, 2, 15);
    g.add_edge(1, 3, 25);

    graph::Graph mst = Algorithms::prim(g);

    CHECK(mst.has_edge(0, 1));
    CHECK(mst.has_edge(0, 2));
    CHECK(mst.has_edge(1, 3));
    CHECK(mst.has_edge(2, 4));
    CHECK(mst.has_edge(3, 5));
}
