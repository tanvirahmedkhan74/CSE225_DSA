#include <bits/stdc++.h>

class DoublyLinkedList{
    struct NodeType{
        int data;
        NodeType* prev;
        NodeType* next;
    };

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void InsertHead(int);
        void InsertEnd(int);
        void InsertMid(int, int);

        void deleteHead();
        void deleteTail();
        void deleteMid(int);

        void printList();

    private:
        NodeType* front;
        NodeType* rear;
};

DoublyLinkedList::DoublyLinkedList(){
    front = nullptr;
    rear = nullptr;
}

void DoublyLinkedList::InsertHead(int val){
    NodeType* temp = new NodeType;
    temp->data = val;

    if(front == nullptr) front = temp;
    else{
        temp->next = front;
        front->prev = temp;
        temp->prev = nullptr;

        front = temp; 
    }

    if(rear == nullptr){
        rear = temp;
    }
}

void DoublyLinkedList::InsertEnd(int val){
    NodeType* temp = new NodeType;
    temp->data = val;

    if(rear == nullptr){
        rear = temp;
    }else{
        rear->next = temp;
        temp->prev = rear;
        temp->next = nullptr;

    rear = temp;
    }  
}

void DoublyLinkedList::printList(){
    NodeType* n = new  NodeType;
    n = front;

    while(n != nullptr){
        std::cout << n->data << " ";
        n = n->next;
    }
}

DoublyLinkedList::~DoublyLinkedList(){
    delete front;
    delete rear;
}
int main(){
    DoublyLinkedList dl = DoublyLinkedList();

    dl.InsertHead(20);
    dl.InsertEnd(30);
    dl.InsertHead(10);

    dl.printList();
}