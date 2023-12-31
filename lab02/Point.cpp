//
// Created by Boti on 10/2/2023.
//

#include "Point.h"
#include "iostream"
#include "../lab04/Point.h"


using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}


void Point::print() const {
    cout << "Point(" << x << ", " << y << ")" << endl;
}
