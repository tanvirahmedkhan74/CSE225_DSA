#include "complex.h"
#include<iostream>

Complex::Complex(){
    real = 0;
    imaginary = 0;
}

Complex::Complex(double r, double im){
    real = r;
    imaginary = im;
}

bool Complex::operator!=(Complex c){
    if(real != c.real || imaginary != c.imaginary) return false;
    else return true;
}

Complex Complex::operator*(Complex c){
    Complex temp;

    temp.real = (real*c.real - imaginary*c.imaginary);
    imaginary = (real * c.imaginary + imaginary*c.real);

    return temp;
}

void Complex::PrintComplex(){
    std::cout << real << " " << imaginary << "i" << "\n";
}
