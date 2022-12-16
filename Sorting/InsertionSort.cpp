#include <iostream>


template <class T>
void swap(T &a, T &b){
    T temp = a;

    a = b;
    b = temp;
}

template <class T>
void Insert(T arr[], int st, int end){
    int current = end;
    bool go = true;

    while(current > st && go){
        if(arr[current] < arr[current - 1]){
            swap(arr[current], arr[current - 1]);
            current--;
        }else go = false;
    }
}

template <class T>
void InsertionSort(T arr[], int size){
    for(int i=1;i<size;i++){
        Insert(arr, 0, i);
    }
}

int main(){
    int arr[] = {5, 7, 13, 2, 10};

    // for(int i: arr){
    //     std::cout << i << " ";
    // }
    // std::cout << "\n";

    InsertionSort(arr, 5);

    for(int i: arr){
        std::cout << i << " ";
    }
    std::cout << "\n";
}