#include <iostream>
#include "graph.h"
#include <time.h>//To generate random graph

bool Graph::is_empty()
{

    if (head == nullptr)
    {
        return true;
    }
    return false;
}

bool Graph::is_directed()
{
    return false;
}

void Graph::add_vertex(int new_vertex)
{

    if (is_empty())
    {
        head = new Node();
        head->data = new_vertex;
        return;
    }

    Node *temp = head;
    while (temp->down != nullptr)
    {
        if (temp->data == new_vertex)
            return;
        temp = temp->down;
    }

    temp->down = new Node();
    temp->down->data = new_vertex;
}

void Graph::add_edge(int vertex1, int vertex2)
{
    if (!is_empty())
    {
        Node *vert = head;
        while (vert != nullptr)
        {
            if (vert->data == vertex1 || vert->data == vertex2)
            {
                Node *temp = vert;
                int data = temp->data;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = new Node();
                temp->next->data = data == vertex1 ? vertex2 : vertex1;
            }
            vert = vert->down;
        }
        counter++;
    }
}

void Graph::remove_vertex(int vertex)

{
    Node *prev = nullptr;
    Node *current = head;
    if (head->data == vertex)
    {
        current = head;
        head = head->down;
        delete current;
        return;
    }
    while (current != nullptr && current->data != vertex)
    {
        prev = current;
        current = current->down;
    }
    if (current == nullptr)
        return;
    prev->down = current->down;
    current->down = nullptr;
    delete current;
}

void Graph::remove_Edge(Node *vertexnode, int vertex)
{

    Node *prev = nullptr;
    Node *current = vertexnode;

    while (current != nullptr && current->data != vertex)
    {
        prev = current;
        current = current->next;
    }
    if (current == nullptr)
        return;
    prev->next = current->next;
    current->next = nullptr;
    delete current;
}



int Graph::show_numof_vertices()
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->down;
    }
    std::cout << "The total num of vertices is ";
    return count;
}


int Graph::show_numof_edges()
{

    return counter++;
}

bool Graph::is_neighbour(int vertex1, int vertex2)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == vertex1)
        {

            while (temp)
            {
                if (temp->data == vertex2)
                {
                    return true;
                }
                temp = temp->next;
            }
        }
        temp = temp->down;
    }
    return false;
}

int Graph::show_indegree(int vertex)
{

    int count = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == vertex)
        {
            while (temp->next)
            {
                count++;
                temp = temp->next;
            }
            break;
        }
        temp = temp->down;
    }

    return count;
}

int Graph::show_outdegree(int vertex)
{

    return show_indegree(vertex);
}

int Graph::show_degree(int vertex)
{

    return show_indegree(vertex) + show_outdegree(vertex);
}

void Graph::show_neighbours(int vertex)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == vertex)
        {
            std::cout << vertex << "->";

            while (temp->next)
            {
                temp = temp->next;
                std::cout << temp->data << "->";
            }
            std::cout << std::endl;
            break;
        }
        temp = temp->down;
    }
    
}

void Graph::randomGraph(int noOfVertices)
{

    srand(time(0));
    for(int i=0;i<noOfVertices;i++)
    {
        this->add_vertex(rand());
    }

    Node *temp = head;

    while(temp!= nullptr)
    {
         Node *temp1 = head;
        while(temp1!= nullptr)
        {
            if(rand()>( temp1->data + temp->data)/2)
            {
                add_edge(temp->data, temp1->data);
            
            }
            temp1 = temp1->down;
           
        }

        temp = temp->down;
       
    }

}