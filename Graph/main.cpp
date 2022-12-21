#include <iostream>
#include "graphtype.cpp"

template <class T>
void hasEdge(GraphType<T>& graph,T u, T v){
    if(graph.FoundEdge(u, v)){
        std::cout << "There is an Edge\n";
    }else std::cout << "There is no Edge\n";
}

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

    std::cout << graph.OutDegree('D') << "\n";

    hasEdge(graph, 'A', 'D');
    hasEdge(graph, 'B', 'D');

    graph.DepthFirstSearch('B', 'E');
    graph.DepthFirstSearch('E', 'B');

    graph.BreadthFirstSearch('B', 'E');
    graph.BreadthFirstSearch('E', 'B');

    graph.BFS_Shortest_Len('B', 'E');
    return 0;
}
