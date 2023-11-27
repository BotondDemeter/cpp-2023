//
// Created by Boti on 11/27/2023.
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include <vector>
#include "iostream"
#include "Alkalmazott.h"

using namespace std;
class Manager : public Alkalmazott{
private:
    vector <Alkalmazott*> alkalmazottak;
public:
    Manager(const string &vezeteknev, const string &keresztNev, int szuletesiEv, const string &munkakor);
    void addAlkalmazott(Alkalmazott* alkalmazott);
    void deleteAlkalmazott(Alkalmazott* alkalmazott);
};

#endif //CPP_2022_MANAGER_H
