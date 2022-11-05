#include <iostream>
#include "carInfo.h"
#include "sortedType.cpp"

template <class T>
void Insert(SortedType<T>& arr, T item){
    if(!arr.IsFull()){
        arr.InsertItem(item);
    }else std::cout << "Array is Full\n";
}

void Print(SortedType<CarInfo>& arr){
    CarInfo temp = CarInfo();

    for(int i=0;i<arr.LengthIs();i++){
        arr.GetNextItem(temp);
        temp.Print();
    }
    std::cout << "\n";
    arr.ResetList();
}

template <class T>
void RetrieveItem(SortedType<T>& arr, T item){
    bool found = false;
    arr.RetrieveItem(item, found);

    if(found) std::cout << "Item is Found\n";
    else std::cout << "Item is not Found\n";
}

template <class T>
void ListState(SortedType<T>& arr){
    if(arr.IsFull()) std::cout << "List is Full\n";
    else std::cout << "List is not Full\n";
}

int main()
{
    SortedType<CarInfo> arr = SortedType<CarInfo>();

    CarInfo c1 = CarInfo(20000, 2017);
    CarInfo c2 = CarInfo(50000, 2022);
    CarInfo c3 = CarInfo(40000, 2018);

    Insert(arr, c1);
    Insert(arr, c2);
    Insert(arr, c3);

    Print(arr);

    arr.DeleteItem(c1);

    Print(arr);
}
