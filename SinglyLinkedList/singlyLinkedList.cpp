#include "singlyLinkedList.h"
#include<iostream>

template <class T>
Node<T>::Node(T item){
    data = item;
    next = nullptr;
}

//template <class T>
//explicit SinglyLinkedList<T>::SinglylinkedList(){
//    head = nullptr;
//}

template <class T>
void SinglyLinkedList<T>::insertLeft(T item){
    Node<T> *new_node = new Node<T>(item);

    if(head != nullptr){
        Node<T> *new_node = new Node<T>(item);
        new_node->next = head;
        head = new_node;
    }else head = new_node;

    sz++;
}

int SinglyLinkedList<T>::getSize(){
    return sz;
}

template <class T>
void SinglyLinkedList<T>::insertRight(T item){
    Node<T> *new_node = new Node<T>(item);

    if(head != nullptr){
        Node<T> *new_node = new Node<T>(item);

        Node<T> *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = new_node;
    }else head = new_node;
}
template <class T>
void SinglyLinkedList<T>::insertAt(T item, int pos){
    if(pos > 0 && pos <= sz+1){
        if(pos == 1){
            insertLeft(item);
        }else if(pos == sz+1){
            insertRight(item);
        }else{
            Node<T> *new_node = new Node<T>(item);
            Node<T> *temp = head;

            for(int i=0;i<sz-2;i++){
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;
        }
    }else std::cout << "Invalid Length\n";
}

template <class T>
void SinglyLinkedList<T>::printList(){
    Node<T> *temp = head;

    while(temp!= nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << "\n";
}


