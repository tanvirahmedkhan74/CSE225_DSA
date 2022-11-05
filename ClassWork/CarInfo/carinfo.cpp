#include "carInfo.h"
#include <iostream>

CarInfo::CarInfo(){
    year = 0;
    price = 0;
}

CarInfo::CarInfo(double pr, int yr){
    price = pr;
    year = yr;
}

bool CarInfo::operator!=(CarInfo c){
    return (price != c.price);
}

bool CarInfo::operator==(CarInfo c){
    return (price == c.price);
}

bool CarInfo::operator<(CarInfo c){
    return (price < c.price);
}

bool CarInfo::operator>(CarInfo c){
    return (price > c.price);
}

void CarInfo::Print(){
    std::cout << "Year = " << year << " " << "Price: " << price << "\n";
}
