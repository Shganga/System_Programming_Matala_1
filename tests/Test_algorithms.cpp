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

    // Verify the shortest path tree (correct edges with minimum weight)
    CHECK(spt.has_edge(0, 1));  // 0 -> 1 (weight 10)
    CHECK(spt.has_edge(1, 2));  // 1 -> 2 (weight 30)
    CHECK(spt.has_edge(2, 3));  // 2 -> 3 (weight 30)
    CHECK(spt.has_edge(3, 4));  // 3 -> 4 (weight 10)

    // Verify the correct shortest path weights
    CHECK(spt.get_edge_weight(0, 1) == 10);  // Weight from 0 to 1
    CHECK(spt.get_edge_weight(1, 2) == 30);  // Weight from 1 to 2
    CHECK(spt.get_edge_weight(2, 3) == 30);  // Weight from 2 to 3
    CHECK(spt.get_edge_weight(3, 4) == 10);  // Weight from 3 to 4

    // Verify that the shortest path from 0 to 4 is through 0 -> 1 -> 2 -> 3 -> 4
    CHECK(spt.has_edge(0, 1));
    CHECK(spt.has_edge(1, 2));
    CHECK(spt.has_edge(2, 3));
    CHECK(spt.has_edge(3, 4));

    // Verify that an unnecessary edge (0 -> 4) does not exist in the shortest path tree
    CHECK_FALSE(spt.has_edge(0, 4));  // Edge 0 -> 4 should not be present, it's not part of the shortest path

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

    CHECK(mst.has_edge(0, 1));  // Edge from 0 to 1 (weight 10)
    CHECK(mst.has_edge(0, 2));  // Edge from 0 to 2 (weight 15)
    CHECK(mst.has_edge(1, 3));  // Edge from 1 to 3 (weight 25)
    CHECK(mst.has_edge(3, 4));  // Edge from 3 to 4 (weight 40)
    CHECK(mst.has_edge(4, 5));  // Edge from 4 to 5 (weight 50)

    // Ensure that non-MST edges are not present
    CHECK_FALSE(mst.has_edge(2, 3));  // Edge from 2 to 3 (weight 30) should not be in MST
    CHECK_FALSE(mst.has_edge(1, 2));  // Edge from 1 to 2 (weight 20) should not be in MST

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

    CHECK(mst.has_edge(0, 1));  // Direct edge in MST
    CHECK(mst.has_edge(0, 2));  // Direct edge in MST (corrected)
    CHECK(mst.has_edge(1, 3));  // Direct edge in MST
    CHECK(mst.has_edge(3, 4));  // Direct edge in MST
    CHECK(mst.has_edge(4, 5));  // Direct edge in MST

    CHECK_FALSE(mst.has_edge(1, 2));  // This edge should not exist
}

