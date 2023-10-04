//
// Created by Boti on 10/2/2023.
//

#include <cmath>
#include "util.h"

double distance(const Point &a, const Point &b) {
    return sqrt(((a.getY() - a.getX()) * (a.getY() - a.getX())) + ((b.getY() - b.getX()) * (b.getY() - b.getX())));
}
