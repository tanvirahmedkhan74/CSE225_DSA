#include <iostream>

class SLL{
    struct Node
    {
        int data;
        Node *next;
    };

    private:
        Node *begin;
    public:
    SLL(){
        begin = nullptr;
    }

    ~SLL(){
        delete begin;
    }

    void insertHead(int val){
        Node *temp = new Node();
        temp->data = val;
        temp->next = begin;
        begin = temp;
    }

    void deleteHead(){
        Node *temp = new Node;
        temp = begin;

        begin = begin->next;
        delete temp;
    }       
    
    void insertEnd(int val){
        Node *temp = new Node;
        temp->data = val;
        temp->next = nullptr;

        Node *t = begin;
        while(t->next != nullptr){
            t = t->next;
        }
        t->next = temp;
    }

    void deleteEnd(){
        Node *temp = begin;
        Node *del;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }

        del = temp->next;
        temp->next = nullptr;
        delete del;
    }

    void insertMid(int val, int pos){
        Node *temp = begin;
        Node *notun = new Node;
        notun->data = val;

        for(int i=0;i<pos-2;i++){
            temp = temp ->next;
        }

        notun->next = temp->next;
        temp->next = notun;
    }

    void deleteMid(int pos){
        Node *temp = begin;

        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = temp->next->next;

        delete del;
    }

    void Print(){
        Node *temp = begin;

        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    SLL s = SLL();

    s.insertHead(20);
    s.insertHead(30);
    s.deleteHead();
    s.insertEnd(40);
    s.insertHead(10);
    s.insertMid(5, 2);
    s.Print();
}