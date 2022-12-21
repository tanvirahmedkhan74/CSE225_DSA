#include <iostream>
#include "graphtype.cpp"

int main()
{
    GraphType<char> graph = GraphType<char>(8);

    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');
    graph.AddVertex('D');
    graph.AddVertex('E');
    graph.AddVertex('F');
    graph.AddVertex('G');
    graph.AddVertex('H');

    graph.AddEdge('A', 'B', 1);
    graph.AddEdge('A', 'C', 1);
    graph.AddEdge('A', 'D', 1);
    graph.AddEdge('B', 'A', 1);
    graph.AddEdge('D', 'A', 1);
    graph.AddEdge('D', 'G', 1);
    graph.AddEdge('D', 'E', 1);
    graph.AddEdge('G', 'F', 1);
    graph.AddEdge('F', 'H', 1);
    graph.AddEdge('H', 'E', 1);

    graph.DepthFirstSearch('B', 'E');
    graph.BFS_Shortest_Len('B', 'E');
    return 0;
}
