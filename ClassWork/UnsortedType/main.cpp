#include <iostream>
#include "unsortedType.cpp"

template <class T>
void Insert(UnsortedType<T> & temp, T item){
    if(temp.IsFull()){
        std::cout << "FUll\n";
    }else temp.InsertItem(item);
}

template <class T>
void Retrieve(UnsortedType<T> & temp, T item){
    bool found = false;
    temp.RetrieveItem(item, found);

    if(!found) std::cout << "Item not Found\n";
    else std::cout << "Item Found\n";
}

template <class T>
void Print(UnsortedType<T> & arr){

    for(int i=0;i<arr.LengthIs();i++){
        int temp;
        arr.GetNextItem(temp);
        std::cout << temp << " ";
    }

    arr.ResetList();
    std::cout << "\n";
}

int main()
{
    UnsortedType<int> arr = UnsortedType<int>();
    Insert(arr, 5);
    Insert(arr, 7);
    Insert(arr, 6);
    Insert(arr, 9);

    Print(arr);
    std::cout << arr.LengthIs() << "\n";

    Insert(arr, 1);

    Print(arr);

    // Retrieve

    Retrieve(arr, 4);
    Retrieve(arr, 5);
    Retrieve(arr, 9);
    Retrieve(arr, 10);

    if(arr.IsFull()) std::cout << "List is Full\n";
    arr.DeleteItem(5);

    if(arr.IsFull()) std::cout << "List is Full\n";
    else std::cout << "List is not Full\n";

    arr.DeleteItem(1);
    Print(arr);

    return 0;
}
