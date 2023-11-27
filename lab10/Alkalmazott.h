//
// Created by Boti on 11/27/2023.
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include "iostream"
#include "Szemely.h"


using namespace std;

class Alkalmazott : public Szemely {
    string munkakor;
protected:
    static int nextID;
    int id;
public:
    Alkalmazott(const string &vezeteknev, const string &keresztNev, int szuletesiEv, const string &munkakor);
    virtual void print(ostream &os) const override;
    int getId() const;
};

#endif //CPP_2022_ALKALMAZOTT_H
