#include<iostream>

// Multi Dimensional Dynamic Character Array

int main(){
    int r, c;
    std::cout << "Enter row and col : ";
    std::cin >> r >> c;

    char *arr = new char[r*c];
    // char * arr = new char[r][c] --> gives an error as c must be a constant

    int idx = 0;
    for(int i=0;i<r;i++){
        std::cout << "Enter a string (less than size c) : ";
        for(int j=0;j<c;j++){
            std::cin >> *(arr + idx++);
        }
    }

    idx = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            std::cout << *(arr + idx++);
        }
        std::cout << "\n";
    }

    delete [] arr;
}
