#include <iostream>


template <class T>
void swap(T &a, T &b){
    T temp = a;

    a = b;
    b = temp;
}

template <class T>
int getMinIdx(T arr[], int st, int end){
    int currentMin = st;

    for(int i=st + 1;i<end;i++){
        if(arr[i] < arr[currentMin]){
            currentMin = i;
        }
    }

    return currentMin;
}

template <class T>
void SelectionSort(T arr[], int size){
    for(int i=0;i<size - 1;i++){
        int min = getMinIdx(arr, i, size);
        swap(arr[i], arr[min]);
    }
}

int main(){
    int arr[] = {5, 7, 13, 2, 10};

    // for(int i: arr){
    //     std::cout << i << " ";
    // }
    // std::cout << "\n";

    SelectionSort(arr, 5);

    for(int i: arr){
        std::cout << i << " ";
    }
    std::cout << "\n";
}