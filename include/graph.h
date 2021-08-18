#pragma once

class Node
{

public:
    int data;
    Node *next;
    Node *down;

    Node(int data)
    {
        this->data = data;
    }

    Node() : next(nullptr), down(nullptr) {}

    ~Node()
    {
        if (next)
        {
            delete next;
        }

        if (down)
        {
            delete down;
        }
    }
};

class Graph
{

    Node *head;

public:
    Graph() : head(nullptr) {}

    bool is_empty();
    bool is_directed();
    void add_vertex(int new_vertex);
    void add_edge(int vertex1, int vertex2);
    void remove_vertex(int vertex);
    void remove_Edge(Node *vertexnode, int vertex);
    int show_numof_vertices();
    int show_numof_edges();
    int show_indegree(int vertex);
    int show_outdegree(int vertex);
    int show_degree(int vertex);
    void show_neighbours(int vertex);
    bool is_neighbour(int vertex1, int vertex2);

    void removing_edge(int vertex)
    {
        Node *temp = head;
        remove_Edge(head, vertex);

        while (temp->down)
        {
            remove_Edge(temp->down, vertex);
            temp = temp->down;
        }
    }

// This is for printing the vertices only....
    void print()
    {
        auto temp = head;
        std::cout << "The vertexes are ";
        while (temp)
        {

            std::cout << temp->data << ',';

            temp = temp->down;
        }
        std::cout << std::endl;
    }

private:
    int counter = 0; //for counting the edges
};
