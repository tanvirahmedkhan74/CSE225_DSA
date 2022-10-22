#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class Complex{
    public:
    Complex();
    Complex(double, double);
    //~Complex();
    void PrintComplex();

    Complex operator*(Complex);
    Complex operator-(Complex);
    Complex operator+(Complex);
    Complex operator/(Complex);

    bool operator!=(Complex);
    bool operator>(Complex);
    bool operator<(Complex);
    bool operator=(Complex);

    private:
    double real, imaginary;
};

#endif // COMPLEX_H_INCLUDED
