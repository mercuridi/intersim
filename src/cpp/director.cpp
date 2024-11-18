#include <iostream>
#include <vector>

#include "../hpp/ledger.hpp"
#include "../hpp/events.hpp"
#include "../hpp/director.hpp"

Director::Director(Calendar &calendarReference, Ledger &ledgerReference, std::vector<Region> &regionsReference) {
    this->calendarReference = &calendarReference;
    this->ledgerReference = &ledgerReference;
    this->regionsReference = &regionsReference;
}

void Director::calculateHistory(int stopYear) {

    while ((*calendarReference).currentYear < stopYear) {
        int d100 = std::rand() % 100;
        if (d100 < 80) {
            continue;
        }
        else {

        }
    }
}
