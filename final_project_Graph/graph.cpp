#include <iostream>
#include <cassert>
#include "graph.h"

int main() {
    // Graph
    graph g(3);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 2);
    g.add_edge(1, 2, 2);
    g.print_vertices();

    // add vertices
    g.add_vertex();
    g.add_vertex();
    g.add_edge(1, 3, 4);
    g.add_edge(1, 4, 1);
    g.add_edge(2, 3, 10);
    g.add_edge(4, 3, 2);
    g.print_vertices();

    // Min Distances
    std::cout << "Min distance from 0 to 3: ";
    std::cout << g.min_distance(0, 3) << std::endl;
    std::cout << "Min distance from 0 to 4: ";
    std::cout << g.min_distance(0, 4) << std::endl;
    std::cout << "Min distance from 0 to 1: ";
    std::cout << g.min_distance(0, 1) << std::endl;

    // Min Spanning Tree
    g.print_vertices();
    std::cout << "Minimum Spanning Tree\n";
    graph mst = g.min_spanning_tree();
    mst.print_vertices();
    return 0;
}