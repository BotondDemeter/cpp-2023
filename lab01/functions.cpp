//
// Created by Boti on 9/25/2023.
//

#include "functions.h"

int countBits(int number) {
    int count = 0;
    while (number > 0) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int& number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    int mask = 1 << order;
    number |= mask;
    return true;
}

double mean(double *array, int numElements) {
    int mean1;
    for (int i = 0; i < numElements; ++i) {
        mean1 += array[i];
    }
    return mean1;
}

