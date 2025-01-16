#include <iostream>
#include <vector>

#include "../hpp/ledger.hpp"
#include "../hpp/events.hpp"
#include "../hpp/director.hpp"

Director::Director(Calendar *calendarReference, Ledger *ledgerReference, std::vector<Region> *regionsReference) {
    this->calendarPtr = calendarReference;
    this->ledgerPtr = ledgerReference;
    this->regionsPtr = regionsReference;
}

void Director::calculateHistory(int stopYear) {

    while ((*calendarPtr).currentYear < stopYear) {
        (*calendarPtr).incrementYear();
        int d100 = std::rand() % 100;
        if (d100 < 80) {
            continue;
        }
        else {
            std::cout << "start a war!!!!";
        }
    }
}
