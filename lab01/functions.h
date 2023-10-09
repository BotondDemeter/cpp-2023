//
// Created by Boti on 9/25/2023.
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H


#include <string>

using namespace std;

int countBits(int n);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
int countWords(string text);
string code(string text);
string decode(string text);
string capitalizeWords(string text);

#endif //CPP_2022_FUNCTIONS_H
