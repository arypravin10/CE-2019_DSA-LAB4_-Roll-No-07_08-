#include <iostream>
#include "graph.h"

int main()
{

    Graph g;

    // checking whether vertex is empty or not initially
    std::cout << g.is_empty() << std::endl;

    // Adding the vertices
    g.add_vertex(5);
    g.add_vertex(2);
    g.add_vertex(4);
    g.add_vertex(3);

    // printing the vertices
    g.print();

    // printing total num of vertices
    std::cout << g.show_numof_vertices() << std::endl;

    // adding edges between two vertices
    g.add_edge(2, 3);
    g.add_edge(5, 2);

    // Printing neighbours
    g.show_neighbours(5);
    g.show_neighbours(2);

    // checking whether graph is directed or not since we have implement function for undirected graph it returns false.
    std::cout << g.is_directed() << std::endl;

    // printing indegree of vertex

    std::cout << "The indegree of vertex 2 is ";
    std::cout << g.show_indegree(2) << std::endl;

    // printing neighbours of vertex
    g.show_neighbours(3);

// printing outdegree of vertex
    std::cout << "The indegree of vertex 3 is ";
    std::cout << g.show_indegree(3) << std::endl;

    // printing total degree of a vertex
    std::cout << "The degree of vertex 3 is ";
    std::cout << g.show_degree(3) << std::endl;

    // printing total num of edges
    std::cout << "The total num of edges is ";
    std::cout << g.show_numof_edges();
    std::cout << std::endl;

    // checking if one vertex is neighbour of another vertex or not
    std::cout << g.is_neighbour(2, 5) << std::endl;

    //  removing vertex and its edges
    g.remove_vertex(3);
    g.removing_edge(3);

    //  checking if vertex 3 has been removed or not
    g.show_neighbours(3);

    // checking if the neighbour 3 in 2 has also been  removed or not
    g.show_neighbours(2);
}