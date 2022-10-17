#include <iostream>
#include "DynArr.h"


int main()
{
    DynArr ar = DynArr(3, 3);
    ar.setValue(1,2,3);
    std::cout << ar.getValue(1,2);
    return 0;
}
