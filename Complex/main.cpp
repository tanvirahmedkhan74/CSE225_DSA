#include <iostream>
#include "complex.h"

int main()
{
    Complex a = Complex(10, 20);
    Complex b = Complex(20, 30);

    Complex c = a * b;
    c.PrintComplex();
}
