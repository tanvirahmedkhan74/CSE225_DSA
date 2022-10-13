#include <iostream>

//Dynamic 2d Array
int main()
{
    int r, c;
    r = 4, c = 3;

    int **arr = new int*[r];

    for(int i=0;i<r;i++){
        *(arr + i) = new int[c];
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            std::cout << *(*(arr + i) + j) << " ";
        }
    }

    // Del mem

    for(int i=0;i<r;i++){
        delete [] arr[i];
    }

    delete [] arr;
    
}
