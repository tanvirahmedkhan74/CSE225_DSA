#include<iostream>
class IsFull{};
class IsEmpty{};

class Queue{
    public:
        Queue(int);
        ~Queue();

        bool isFull();
        bool isEmpty();

        void Append(int);
        void Pop(int &);

        int peek();

    private:
        int max, front, rear;
        int *items;
};

Queue::Queue(int mx){
    max = mx + 1;
    front = max - 1;
    rear = max - 1;

    items = new int[max];
}

Queue::~Queue(){
    delete items;
}

bool Queue::isEmpty(){
    return (rear == front);
}

bool Queue::isFull(){
    return (rear + 1) % max == front;
}

void Queue::Append(int val){
    if(isFull()){
        throw IsFull();
        return;
    }

    rear = (rear + 1) % max;
    items[rear] = val;
}

void Queue::Pop(int & val){
    if(isEmpty()){
        throw IsEmpty();
        return;
    }
    front = (front + 1) % max;
    val = items[front];
}

int Queue::peek(){
    return items[rear];
}

int main(){
    Queue q = Queue(6);
    int temp;

    q.Append(10);
    q.Append(20);
    q.Append(30);
    
    while(!q.isEmpty()){
        q.Pop(temp);
        std::cout << temp << " ";
    }
}