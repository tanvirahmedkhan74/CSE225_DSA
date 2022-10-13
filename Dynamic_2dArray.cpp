#include <iostream>

//Dynamic 2d Array

int main()
{
    int r;
    std::cout << "Enter row : ";
    std::cin >> r;

    int *col_arr = new int[r];

    int **arr = new int*[r];

    std::cout << "Enter Columns of Each Row: ";

    // Taking the variation of Columns input
    for(int i=0;i<r;i++){
        std::cin >> *(col_arr + i); // col_arr[i]
    }

    // Creating the Dynamic Columns
    for(int i=0;i<r;i++){
        *(arr + i) = new int[*(col_arr + i)];
    }

    //Taking the Array Input
    for(int i=0;i<r;i++){
        for(int j = 0;j< *(col_arr + i);j++){
            std::cin >> *(*(arr + i) + j);
        }
    }

    // Printing out the Array
    for(int i=0;i<r;i++){
        for(int j = 0;j< *(col_arr + i);j++){
            std::cout << *(*(arr + i) + j) << " ";
        }
        std::cout << "\n";
    }

    for(int i=0;i<r;i++){
        delete [] *(arr + i);
    }
    delete [] arr;
}
