//
// Created by Boti on 9/25/2023.
//

#include <cmath>
#include "functions.h"
#include <utility>
#include <string>
#include <sstream>

using namespace std;

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
    if(numElements <=0){
        return NAN;
    }
    double mean1;
    for (int i = 0; i < numElements; ++i) {
        mean1 += array[i];
    }
    return mean1 / numElements;
}

double stddev(double *array, int numElements) {
    double mean1 = mean(array, numElements);
    double variance = 0;
    for (int i = 0; i < numElements; i++) {
        variance += pow(array[i] - mean1, 2);
    }
    double stdDev = sqrt(variance / (numElements));
    return stdDev;
}

pair<double, double> max2(double *array, int numElements) {
    if(numElements <=0)
        return make_pair(nan(""), nan(""));
    else if(numElements == 1)
        return make_pair(array[0], array[0]);
    else{
        double max1 = max(array[0], array[1]);
        double max2 = min(array[0], array[1]);
        for (int i = 2; i < numElements; ++i) {
            if(array[i] > max1) {
                max2 = max1;
                max1 = array[i];
            }
            else if(array[i] > max2)
                max2 = array[i];
        }
        return make_pair(max2, max1);
    }
}

int countWords(string text) {
    istringstream iss(text);
    int wordCount = 0;
    string word;
    while(iss >> word)
        wordCount ++;
    return wordCount;
}

string code(string text) {
    for(char &c : text){
        if(isalpha(c)){
            if(c == 'z')
                c = 'a';
            else if(c == 'Z')
                c = 'A';
            else
                c ++;
        }
    }
    return text;
}

string decode(string text) {
    for(char &c : text){
        if(isalpha(c)){
            if(c == 'a')
                c = 'z';
            else if(c == 'A')
                c = 'Z';
            else
                c --;
        }
    }
    return text;
}

string capitalizeWords(string text) {
    istringstream iss(text);
    string result = "";
    bool firstWord = true;
    while(iss >> text){
        if(!firstWord)
            result += " ";
        else
            firstWord = false;
        for(size_t i = 0; i < text.length(); ++i){
            if(i == 0)
                result += toupper(text[i]);
            else
                result += tolower(text[i]);
        }
    }
    return result;
}


