//
// Created by Boti on 10/2/2023.
//

#include <cmath>
#include <iostream>
#include <vector>
#include "util.h"
#include "fstream"
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;
double distance(const Point &a, const Point &b) {
    return sqrt(((a.getY() - a.getX()) * (a.getY() - a.getX())) + ((b.getY() - b.getX()) * (b.getY() - b.getX())));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double ab = distance(a, b);
    double ac = distance(a, c);
    double ad = distance(a, d);
    double bc = distance(b, c);
    double bd = distance(b, d);
    double cd = distance(c, d);
    if (ab > 0 && ab == bc && ab == cd && ab == ad)
        return true;
    return false;
}

void testIsSquare(const char *filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Nem sikerult megnyitni a filet!";
        return;
    }
    vector<Point> points;
    int x, y;
    while (file >> x >> y) {
        Point p = {x, y};
        points.push_back(p);
    }
    file.close();
    for (size_t i = 0; i < points.size(); i += 4) {
        Point a = points[i];
        Point b = points[i + 1];
        Point c = points[i + 2];
        Point d = points[i + 3];
        if (isSquare(a, b, c, d))
            cout << a.getX() << " " << a.getY() << " " << b.getX() << " " << b.getY() << " " << c.getX() << " "
                 << c.getY() << " " << d.getX() << " " << d.getY() << " YES" << endl;
        else
            cout << a.getX() << " " << a.getY() << " " << b.getX() << " " << b.getY() << " " << c.getX() << " "
                 << c.getY() << " " << d.getX() << " " << d.getY() << " NO" << endl;
    }
}

Point *createArray(int numPoints) {
    Point * points = new Point[numPoints];
    srand(time(nullptr));
    for(int i = 0; i < numPoints; ++i){
        points[i].x = rand() % 2001;
        points[i].y = rand() % 2001;
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        cout << points[i].x << " " << points[i].y << endl;
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    int closest = INT_MAX;
    pair<Point, Point> closestPair;
    for (int i = 0; i < numPoints; ++i) {
        if(distance(points[i].x, points[i].y) < closest)
            closestPair = make_pair(points[i].getX(), points[i].getY());
    }
    return closestPair;
}
