//
// Created by Boti on 11/27/2023.
//

#include "Szemely.h"

Szemely::Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv) : vezetekNev(vezetekNev),
                                                                                        keresztNev(keresztNev),
                                                                                        szuletesiEv(szuletesiEv) {}
ostream& operator<<(ostream &os, const Szemely& sz) {
    sz.print(os);
    return os;
}

void Szemely::print(ostream &os) const {
    os << "Vezeteknev: " << vezetekNev << endl;
    os << "Keresztnev: " << keresztNev << endl;
    os << "Szuletesi ev: " << szuletesiEv << endl;
}
