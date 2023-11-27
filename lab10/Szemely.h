//
// Created by Boti on 11/27/2023.
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H

#include "iostream"

using namespace std;

class Szemely {
private:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv);

    virtual void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Szemely &sz);
};

#endif //CPP_2022_SZEMELY_H
