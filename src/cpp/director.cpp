#include <iostream>
#include <vector>

#include "../hpp/ledger.hpp"
#include "../hpp/events.hpp"
#include "../hpp/director.hpp"
#include "../hpp/calendar.hpp"

Director::Director(Calendar *calendarPtr, Ledger *ledgerPtr, std::vector<Region> *regionsPtr) {
    this->calendarPtr   = calendarPtr;
    this->ledgerPtr     = ledgerPtr;
    this->regionsPtr    = regionsPtr;
}

void Director::calculateHistory(int stopYear) {

    while ((*calendarPtr).currentYear < stopYear) {
        (*calendarPtr).incrementYear();
        int d100 = std::rand() % 100;
        if (d100 < 80) {
            continue;
        }
        else {
            std::vector<Region*> allies = {&(*regionsPtr)[0]};
            std::vector<Region*> axis = {&(*regionsPtr)[1]};
            War thisWar(allies, axis);
        }
    }
}
