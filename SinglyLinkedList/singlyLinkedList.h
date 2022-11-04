#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

template <class T>
class Node{
public:
    Node(T);
private:
    T data;
    Node *next;
};

template <class T>
class SinglyLinkedList{
public:
    SinglyLinkedList();

    void insertLeft(T);
    void insertRight(T);
    void insertAt(T);
    void popLeft();
    void popRight();
    void popAt(int);
    void pop(T);

    T getItem(int);
    bool searchItem(T);
    int getSize();
    void printList();
private:
    Node<T> *head;
    int sz = 0;
};

#endif // SINGLYLINKEDLIST_H_INCLUDED
