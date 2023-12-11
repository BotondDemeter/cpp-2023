#include <iostream>
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"

int main() {
    //Settlement settlement = {"Marosv", "MS", 3445645};
    //cout << settlement;
    SettlementStatisticsImpl statistics;
    cout << "Settlements: " << statistics.numSettlements();
}