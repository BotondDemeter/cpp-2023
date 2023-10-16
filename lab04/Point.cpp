//
// Created by Boti on 10/16/2023.
//

#include <iostream>
#include <valarray>
#include "Point.h"

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

double Point :: distances(Point point1) const{
    return sqrt(pow(this->x - point1.x, 2) + pow(this->y - point1.y, 2));
}