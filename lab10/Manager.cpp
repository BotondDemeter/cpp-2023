//
// Created by Boti on 11/27/2023.
//

#include "Manager.h"
#include <algorithm>


using namespace std;
Manager::Manager(const string &vezeteknev, const string &keresztNev, int szuletesiEv, const string &munkakor)
        : Alkalmazott(vezeteknev, keresztNev, szuletesiEv, munkakor) {}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    auto it = find(alkalmazottak.begin(), alkalmazottak.end(), alkalmazott);
    if(it != alkalmazottak.end()){
        alkalmazottak.erase(it);
    }
}

int Manager::beosztottakSzama() {
    return alkalmazottak.size();
}

void Manager::print(ostream & os) {
    os << "Manager informaciok:" << endl;
    Alkalmazott::print(os);
    os << "Alkalmazottak:" << endl;
    for(const auto& alkalmazott : alkalmazottak){
        alkalmazott->print(os);
        os << endl;
    }
}
const string Manager::MANAGER_MUNKAKOR = "manager";


