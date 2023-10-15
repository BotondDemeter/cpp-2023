//
// Created by Boti on 10/2/2023.
//

#ifndef CPP_2022_UTIL_H
#define CPP_2022_UTIL_H

#include "Point.h"

using namespace std;

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);


#endif //CPP_2022_UTIL_H
