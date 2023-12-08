//
// Created by Boti on 11/27/2023.
//

#include "Alkalmazott.h"
#include "Szemely.h"


int Alkalmazott::nextID =1;

Alkalmazott::Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv,
                         const string &munkakor) : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor) {
    id = nextID++;
}

void Alkalmazott::print(ostream &os) const {
    Szemely::print(os);
    os << "Munkakor: " << munkakor << endl;
}

int Alkalmazott::getId() const {
    return id;
}


