//
// Created by Boti on 12/11/2023.
//

#include <fstream>
#include <sstream>
#include "SettlementStatisticsImpl.h"

typedef multimap<string, Settlement>::const_iterator MIT;

SettlementStatisticsImpl::SettlementStatisticsImpl() {
    ifstream file("telepulesek.csv");
    if(!file){
        cerr << "Error opening file!";
        return;
    }
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        string name;
        getline(iss, name, ',');
        string county;
        getline(iss, county, ',');
        string word;
        getline(iss, word);
        int population = 0;
        if (!word.empty())
            population = stoi(word);
        settlementMap.insert({county, Settlement(name, county, population)});
    }
    file.close();
}

int SettlementStatisticsImpl::numSettlements() const {
    return settlementMap.size();
}

int SettlementStatisticsImpl::numCounties() const {
    return 0;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return 0;
}
vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    return vector<Settlement>();
}


Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    return vector<Settlement>();
}
