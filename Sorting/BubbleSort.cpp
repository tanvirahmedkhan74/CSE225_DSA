#include <iostream>

template <class T>
void swap(T &a, T &b){
    T temp = a;

    a = b;
    b = temp;
}

template <class T>
void BubbleUp(T arr[], int st, int end, bool flag){
    for(int idx = end;idx>st;idx--){
        if(arr[idx - 1] > arr[idx]){
            swap(arr[idx - 1], arr[idx]);
            flag = false;
        }
    }
}

template <class T>
void BubbleSort(T arr[], int size){
    int current = 0;
    bool flag = false;

    while(current < size - 1 && !flag){
        flag = true;
        BubbleUp(arr, current, size - 1, flag);

        // for(int i=0;i<size;i++){
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << "\n";

        current++;
    }
}

int main(){
    int arr[] = {5, 7, 13, 2, 10};

    // for(int i: arr){
    //     std::cout << i << " ";
    // }
    // std::cout << "\n";

    BubbleSort(arr, 5);

    for(int i: arr){
        std::cout << i << " ";
    }
    std::cout << "\n";
}