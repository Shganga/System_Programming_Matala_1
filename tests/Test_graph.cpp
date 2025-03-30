#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Edge.hpp"

TEST_CASE("Graph class functionality") {
    graph::Graph g(5);

    g.add_edge(0, 1, 10);
    g.add_edge(1, 2, 20);
    g.add_edge(2, 3, 30);
    g.add_edge(3, 4, 40);
    g.remove_edge(1, 2);

    // Checking the existence of edges
    CHECK(g.has_edge(0, 1));  // Should have an edge between 0 and 1
    CHECK_FALSE(g.has_edge(1, 2));  // Should NOT have an edge between 1 and 2 after removal
    CHECK(g.has_edge(2, 3));  // Should have an edge between 2 and 3
    CHECK(g.has_edge(3, 4));  // Should have an edge between 3 and 4
    CHECK_FALSE(g.has_edge(4, 0));  // Should NOT have an edge between 4 and 0

    // Check that each vertex has the expected number of edges
    int count_0 = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;

    for (int i = 0; i < 5; ++i) {
        if (g.has_edge(0, i)) count_0++;
        if (g.has_edge(1, i)) count_1++;
        if (g.has_edge(2, i)) count_2++;
        if (g.has_edge(3, i)) count_3++;
        if (g.has_edge(4, i)) count_4++;
    }

    // Verifying the number of edges for each vertex
    CHECK(count_0 == 1);  // Vertex 0 should have 1 edge (to vertex 1)
    CHECK(count_1 == 1);  // Vertex 1 should have 1 edge (to vertex 0)
    CHECK(count_2 == 1);  // Vertex 2 should have 1 edge (to vertex 3)
    CHECK(count_3 == 2);  // Vertex 3 should have 2 edges (to vertex 2 and 4)
    CHECK(count_4 == 1);  // Vertex 4 should have 1 edge (to vertex 3)
}
