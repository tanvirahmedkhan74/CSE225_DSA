#include <iostream>
#include "stacktype.cpp"
#include "quetype.cpp"
#include "graphtype.h"

const int NULL_VAL = 0;

template <class T>
GraphType<T>::GraphType()
{
    maxVertices = 50;
    numVertices = 0;

    vertices = new T[50];
    edges = new int*[50];

    for(int i=0; i<maxVertices; i++)
    {
        edges[i] = new int[maxVertices];
    }
    marks = new bool[maxVertices];
}

template <class T>
GraphType<T>::GraphType(int maxV)
{
    maxVertices = maxV;
    numVertices = 0;

    vertices = new T[maxVertices];
    edges = new int*[maxVertices];

    for(int i=0; i<maxVertices; i++)
    {
        edges[i] = new int[maxVertices];
    }

    marks = new bool[maxVertices];
}

template <class T>
GraphType<T>::~GraphType()
{
    delete [] vertices;
    delete [] marks;

    for(int i=0; i<maxVertices; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;
}

template <class T>
void GraphType<T>::MakeEmpty()
{
    numVertices = 0;
}

template <class T>
bool GraphType<T>::IsEmpty()
{
    return  (numVertices == 0);
}

template <class T>
bool GraphType<T>::IsFull()
{
    return (numVertices == maxVertices);
}

template <class T>
int IndexIs(T* vertices, T vertex){
    int index = 0;

    while(vertices[index] != vertex) index++;
    return index;
}

template <class T>
void GraphType<T>::AddVertex(T item)
{
    if(!IsFull())
    {
        vertices[numVertices] = item;

        for(int i=0; i<maxVertices; i++)
        {
            edges[numVertices][i] = NULL_VAL; // ROW
            edges[i][numVertices] = NULL_VAL; // COl
        }

        numVertices++;
    }
}

template <class T>
void GraphType<T>::AddEdge(T from, T to, int weight){
    int row = IndexIs(vertices, from);
    int col = IndexIs(vertices, to);

    edges[row][col] = weight;
}

template <class T>
int GraphType<T>::WeightIs(T from, T to){
    int row = IndexIs(vertices, from);
    int col = IndexIs(vertices, to);

    return edges[row][col];
}

template <class T>
void GraphType<T>::GetToVertices(T vertex, QueType<T>& adjVertices){
    int from = IndexIs(vertices, vertex);

    for(int to_index = 0;to_index < maxVertices;to_index++){
        if(edges[from][to_index] != NULL_VAL){
            adjVertices.Enqueue(vertices[to_index]);
        }
    }
}

template <class T>
void GraphType<T>::ClearMarks(){
    for(int i=0;i<maxVertices;i++){
        marks[i] = false;
    }
}

template <class T>
void GraphType<T>::MarkVertex(T vertex){
    int index = IndexIs(vertices, vertex);
    marks[index] = true;
}

template <class T>
bool GraphType<T>::IsMarked(T vertex){
    int index = IndexIs(vertices, vertex);

    return marks[index];
}

template <class T>
void GraphType<T>::DepthFirstSearch(T fromVertex, T toVertex){
    StackType<T> stack;
    QueType<T> queue;

    T vertex, item;
    bool found = false;

    stack.Push(fromVertex);

    ClearMarks();
    do{
        vertex = stack.Top();
        stack.Pop();

        if(vertex == toVertex){
            found = true;
            std::cout << vertex << " ";
        }else{
            if(!IsMarked(vertex)){
                MarkVertex(vertex);
                std::cout << vertex << " ";
                GetToVertices(vertex, queue);

                while(!queue.IsEmpty()){
                    queue.Dequeue(item);
                    if(!IsMarked(item)){
                        stack.Push(item);
                    }
                }
            }
        }
    }while(!stack.IsEmpty() && !found);
    std::cout << "\n";

    if(found == false){
        std::cout << "Path not Found!\n";
    }
}

template <class T>
void GraphType<T>::BreadthFirstSearch(T fromVertex, T toVertex){
    QueType<T> queue;
    QueType<T> vertexQ;

    T vertex, item;
    bool found = false;

    ClearMarks();

    queue.Enqueue(fromVertex);
    do{
        queue.Dequeue(vertex);

        if(vertex == toVertex){
            std::cout << vertex << " ";
            found = true;
        }else{
            if(!IsMarked(vertex)){
                MarkVertex(vertex);
                std::cout << vertex << " ";
                GetToVertices(vertex, vertexQ);
                while(!vertexQ.IsEmpty()){
                    vertexQ.Dequeue(item);
                    if(!IsMarked(item)) queue.Enqueue(item);
                }
            }
        }
    }while(!queue.IsEmpty() && !found);
    std::cout << "\n";

    if(!found) std::cout << "Path not found\n";
}

template <class T>
void GraphType<T>::BFS_Shortest_Len(T fromVertex, T toVertex){
    QueType<T> queue;
    QueType<T> vertexQ;
    QueType<int> counts;

    T vertex, item;
    bool found = false;

    ClearMarks();
    int level = 0, ans;

    queue.Enqueue(fromVertex);
    counts.Enqueue(level);

    do{
        queue.Dequeue(vertex);
        counts.Dequeue(ans);

        if(vertex == toVertex){
            std::cout << ans << " ";
            found = true;
        }else{
            if(!IsMarked(vertex)){
                MarkVertex(vertex);
                GetToVertices(vertex, vertexQ);
                if(!vertexQ.IsEmpty()) level++;
                while(!vertexQ.IsEmpty()){
                    vertexQ.Dequeue(item);
                    if(!IsMarked(item)){
                        queue.Enqueue(item);
                        counts.Enqueue(level);
                    }
                }
            }
        }
    }while(!queue.IsEmpty() && !found);
    std::cout << "\n";

    if(!found) std::cout << "Path not found\n";
}

template <class T>
int GraphType<T>::OutDegree(T vertex){
    int index = IndexIs(vertices, vertex);

    int degree = 0;
    for(int i=0;i<maxVertices;i++){
        if(edges[index][i] > 0) degree++;
    }

    return degree;
}

template <class T>
bool GraphType<T>::FoundEdge(T u, T v){
    int row = IndexIs(vertices, u);
    int col = IndexIs(vertices, v);

    return (edges[row][col] > 0);
}
