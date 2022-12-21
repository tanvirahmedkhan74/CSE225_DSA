#ifndef GRAPHTYPE_H_INCLUDED
#define GRAPHTYPE_H_INCLUDED
#include "stacktype.h"
#include "quetype.h"

template<class T>
class GraphType
{
public:
    GraphType();
    GraphType(int maxV);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();

    void AddVertex(T);
    void AddEdge(T, T, int);
    int WeightIs(T, T);

    void GetToVertices(T, QueType<T>&);

    void ClearMarks();
    void MarkVertex(T);
    bool IsMarked(T);

    void DepthFirstSearch(T, T);
    void BreadthFirstSearch(T, T);

    void BFS_Shortest_Len(T fromVertex, T toVertex);
private:
    int numVertices;
    int maxVertices;
    T* vertices;
    int **edges;
    bool* marks;
};

#endif // GRAPHTYPE_H_INCLUDED
