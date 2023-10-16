//
// Created by Boti on 10/16/2023.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"

using namespace std;


PointSet::PointSet(int n) {
    for (int i = 0; i < n; ++i) {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, 50);
        int x = dist(mt);
        int y = dist(mt);
        Point newPoint (x, y);
       /* for (int j = 0; j < points.size(); ++j) {
            ne generaljon egyformat
        }*/
        points.push_back(newPoint);
    }
}

void PointSet::computeDistances() {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist;
            dist = points[i].distances(points[j]);
            cout << "dist: " << dist;
            distances.push_back(dist);
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (int i = 0; i < points.size(); ++i) {
        points[i].print();
    }
}

void PointSet::printDistances() const {
    for (int i = 0; i < distances.size(); ++i) {
        cout << distances[i] << " ";
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(),points.end(), [](const Point &a, const Point &b) -> bool{
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(),points.end(), [](const Point &a, const Point &b) -> bool{
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    vector <double> newVector = distances;
    auto last = unique(newVector.begin(), newVector.end());
    return last - newVector.begin();
}