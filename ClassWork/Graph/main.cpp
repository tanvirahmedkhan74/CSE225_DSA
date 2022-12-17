#include <iostream>

using namespace std;

int main()
{
    GraphType <char> graph;

    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');
    graph.AddVertex('D');
    graph.AddVertex('E');
    graph.AddVertex('F');
    graph.AddVertex('G');
    graph.AddVertex('H');

    graph.AddEdge('A', 'B', 1);
    graph.AddEdge('D', 'E', 1);
    graph.AddEdge('G', 'F', 1);
    graph.AddEdge('H', 'E', 1);
    graph.AddEdge('D', 'A', 1);

    return 0;
}
