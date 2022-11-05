#ifndef CARINFO_H_INCLUDED
#define CARINFO_H_INCLUDED

class CarInfo{

private:
    int year;
    double price;
public:
    CarInfo();
    CarInfo(double, int);
    bool operator<(CarInfo);
    bool operator>(CarInfo);
    bool operator!=(CarInfo);
    bool operator==(CarInfo);

    void Print();
};

#endif // CARINFO_H_INCLUDED
