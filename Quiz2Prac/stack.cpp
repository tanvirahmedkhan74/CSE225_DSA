#include<bits/stdc++.h>

class Stack{
    struct NodeType
    {
        int data;
        NodeType* next;
    };

    public:
        Stack();
        ~Stack();
        void Push(int);
        int Pop();
    private:
        NodeType* topPtr;
    
};


Stack::Stack(){
    topPtr = nullptr;
}

void Stack::Push(int val){
    NodeType* temp = new NodeType;
    
    temp->data = val;
    temp->next = topPtr;
    topPtr = temp;
}

int Stack::Pop(){
    int val = topPtr->data;
    NodeType* temp = topPtr;
    topPtr = topPtr->next;

    delete temp;
    return val;
}

Stack::~Stack(){
    delete topPtr;
}

int main(){
    Stack s = Stack();

    s.Push(10);
    s.Push(20);
    s.Push(30);
    std::cout << s.Pop();
    std::cout << s.Pop();
}