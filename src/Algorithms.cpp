#include "Algorithms.hpp"
#include "UnionFind.hpp"
#include "Queue.hpp"
#include "Stack.hpp"  // You will need to implement this as well
#include "Graph.hpp"  // Include the Graph class

const int Algorithms::INF = 1000000000; // Define constant for infinity

graph::Graph Algorithms::dijkstra(const graph::Graph& graph, int start) {
    int num_vertices = graph.get_num_vertices();
    int* dist = new int[num_vertices];
    bool* visited = new bool[num_vertices]{false};
    int* parent = new int[num_vertices]{-1};  // To reconstruct the shortest path tree

    // Initialize distances to infinity
    for (int i = 0; i < num_vertices; ++i) {
        dist[i] = INF;  // Set to a large number (or your custom INF value)
    }
    dist[start] = 0;  // Start vertex has distance 0

    // Use a priority queue to implement the priority selection of the next node
    Queue q(num_vertices);

    // Enqueue the start vertex with distance 0
    q.enqueue(start, 0);  

    while (!q.is_empty()) {
        int u = q.dequeue();

        // Skip if the vertex is already visited
        if (visited[u]) continue;  
        visited[u] = true;

        // Get the adjacent vertices array
        int* adj_vertices = graph.get_adjacent_vertices(u);
        for (int i = 0; adj_vertices[i] != -1; ++i) {
            int v = adj_vertices[i];
            int weight = graph.get_edge_weight(u, v);

            // Relaxation step: check if we can update the distance to vertex v
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;  // Update the distance to v
                parent[v] = u;  // Update the parent of v to u
                q.enqueue(v, dist[v]);  // Enqueue vertex v with updated distance
            }
        }
        delete[] adj_vertices;  // Free memory for adjacent vertices
    }

    // Construct the shortest path tree (SPT) based on the parent array
    graph::Graph spt(num_vertices);
    for (int i = 0; i < num_vertices; ++i) {
        if (parent[i] != -1) {
            spt.add_edge(i, parent[i], dist[i]);  // Add edge to the SPT
        }
    }

    delete[] dist;
    delete[] visited;
    delete[] parent;

    return spt;
}








graph::Graph Algorithms::bfs(const graph::Graph& graph, int start) {
    int num_vertices = graph.get_num_vertices();
    bool* visited = new bool[num_vertices]{false};
    int* parent = new int[num_vertices]{-1};  // Keep track of parent nodes for tree structure
    Queue q(num_vertices);  // Use the priority queue (although we ignore priority for BFS)
    q.enqueue(start, 0);  // Enqueue the start vertex with priority 0
    visited[start] = true;

    while (!q.is_empty()) {
        int current = q.dequeue();

        // Get the adjacent vertices array
        int* adj_vertices = graph.get_adjacent_vertices(current);
        int i = 0;
        while (adj_vertices[i] != -1) {
            int neighbor = adj_vertices[i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.enqueue(neighbor, 0);  // Enqueue the neighbor with priority 0
            }
            ++i;
        }
        delete[] adj_vertices; // Free memory
    }

    // Rebuild the graph as a BFS tree
    graph::Graph bfs_tree(num_vertices);
    for (int i = 0; i < num_vertices; ++i) {
        if (parent[i] != -1) {
            bfs_tree.add_edge(i, parent[i], 1);  // Add edge from parent to current node
        }
    }

    delete[] visited;
    delete[] parent;

    return bfs_tree;
}




graph::Graph Algorithms::dfs(const graph::Graph& graph, int start) {
    int num_vertices = graph.get_num_vertices();
    bool* visited = new bool[num_vertices]{false};
    int* parent = new int[num_vertices]{-1};  // Keep track of parent nodes for tree structure
    Stack s(num_vertices);  // Use a stack to implement DFS
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int current = s.pop();

        // Get the adjacent vertices array
        int* adj_vertices = graph.get_adjacent_vertices(current);
        int i = 0;
        while (adj_vertices[i] != -1) {
            int neighbor = adj_vertices[i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                s.push(neighbor);
            }
            ++i;
        }
        delete[] adj_vertices; // Free memory
    }

    // Rebuild the graph as a DFS tree
    graph::Graph dfs_tree(num_vertices);
    for (int i = 0; i < num_vertices; ++i) {
        if (parent[i] != -1) {
            dfs_tree.add_edge(i, parent[i], 1);  // Add edge from parent to current node
        }
    }

    delete[] visited;
    delete[] parent;

    return dfs_tree;
}


graph::Graph Algorithms::kruskal(const graph::Graph& graph) {
    int num_vertices = graph.get_num_vertices();
    UnionFind uf(num_vertices);

    // Get all edges using adjacency list
    Edge* edges = nullptr;
    for (int i = 0; i < num_vertices; ++i) {
        int* adj_vertices = graph.get_adjacent_vertices(i);
        int j = 0;
        while (adj_vertices[j] != -1) {
            int v = adj_vertices[j];
            int weight = graph.get_edge_weight(i, v);
            Edge* new_edge = new Edge(v, weight);  // Create edge with destination and weight
            new_edge->set_next(edges);  // Link new edge at the start of the list
            edges = new_edge;  // Update head of edge list
            ++j;
        }
        delete[] adj_vertices;  // Free memory after processing adjacency list
    }

    // Count the number of edges in the linked list
    int num_edges = 0;
    Edge* edge_ptr = edges;
    while (edge_ptr != nullptr) {
        ++num_edges;
        edge_ptr = edge_ptr->get_next();
    }

    // Create a raw array to hold all edges
    Edge** edge_array = new Edge*[num_edges];
    edge_ptr = edges;
    int index = 0;

    // Copy the edges from the linked list to the raw array
    while (edge_ptr != nullptr) {
        edge_array[index++] = edge_ptr;
        edge_ptr = edge_ptr->get_next();
    }

    // Sort edges by weight using a simple bubble sort (since we can't use std::sort)
    for (int i = 0; i < num_edges - 1; ++i) {
        for (int j = 0; j < num_edges - 1 - i; ++j) {
            if (edge_array[j]->getWeight() > edge_array[j + 1]->getWeight()) {
                // Swap edges
                Edge* temp = edge_array[j];
                edge_array[j] = edge_array[j + 1];
                edge_array[j + 1] = temp;
            }
        }
    }

    // Create the Minimum Spanning Tree (MST) graph
    graph::Graph mst(num_vertices);

    // Add edges to the MST if they don't form a cycle
    for (int i = 0; i < num_edges; ++i) {
        Edge* edge = edge_array[i];
        int u = edge->getDestination(); // Get the source node
        int v = edge->getDestination(); // Get the destination node

        if (uf.find(u) != uf.find(v)) {
            mst.add_edge(u, v, edge->getWeight());  // Add edge to MST
            uf.union_sets(u, v);  // Union the sets of u and v to prevent cycle
        }
    }

    // Clean up memory
    delete[] edge_array;

    // Free the linked list of edges
    edge_ptr = edges;
    while (edge_ptr != nullptr) {
        Edge* temp = edge_ptr;
        edge_ptr = edge_ptr->get_next();
        delete temp;  // Delete each edge to free memory
    }

    return mst;
}




graph::Graph Algorithms::prim(const graph::Graph& graph) {
    int num_vertices = graph.get_num_vertices();
    bool* in_mst = new bool[num_vertices]{false};
    int* key = new int[num_vertices];
    int* parent = new int[num_vertices];
    Queue pq(num_vertices);  // Using the PriorityQueue now

    // Initialize keys to infinity
    for (int i = 0; i < num_vertices; ++i) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;  // Start from vertex 0
    pq.enqueue(0, 0);  // Enqueue the starting vertex with key 0

    while (!pq.is_empty()) {
        int u = pq.dequeue();  // Get the vertex with the minimum key value
        in_mst[u] = true;

        // Get the adjacent vertices array
        int* adj_vertices = graph.get_adjacent_vertices(u);
        int i = 0;
        while (adj_vertices[i] != -1) {
            int v = adj_vertices[i];
            int weight = graph.get_edge_weight(u, v);
            // If vertex v is not in MST and weight is less than current key value
            if (!in_mst[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.enqueue(v, key[v]);  // Enqueue v with updated priority (key)
            }
            ++i;
        }
        delete[] adj_vertices; // Free memory
    }

    // Create the minimum spanning tree (MST)
    graph::Graph mst(num_vertices);
    for (int i = 1; i < num_vertices; ++i) {
        if (parent[i] != -1) {
            mst.add_edge(i, parent[i], key[i]);
        }
    }

    delete[] in_mst;
    delete[] key;
    delete[] parent;

    return mst;
}


