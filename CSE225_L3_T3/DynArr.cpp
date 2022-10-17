#include "DynArr.h"
#include<iostream>

DynArr::DynArr(){
    data = NULL;
    row = col = 0;
}

DynArr::DynArr(int r,int c){
    row = r;
    col = c;

    // 2d Array Allocation

    data = new int*[r];

    for(int i=0;i<r;i++){
        *(data + i) = new int[c];
    }
}

DynArr::~DynArr(){
    for(int i=0;i<row;i++){
        delete [] *(data + i);
    }

    delete [] data;
}

void DynArr::setValue(int r, int c, int val){
    *(*(data + r) + c) = val;
}

int DynArr::getValue(int r, int c){
    return *(*(data + r) + c);
}

void DynArr::Allocate(int r, int c){
    int **temp = new int*[r];
    for(int i=0;i<r;i++){
        *(temp + i) = new int[c];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            *(*(temp + i) + j) = *(*(data + i) + j);
        }
    }

    for(int i=0;i<row;i++){
        delete [] *(data + i);
    }

    delete [] data;

    data = temp;
}
