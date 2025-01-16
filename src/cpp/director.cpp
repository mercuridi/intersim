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

void Director::calculateHistory(int stopYear, int maxEvents) {

    // while we haven't hit the max year or max war events
    while (((*calendarPtr).currentYear < stopYear) and 
            ((*ledgerPtr).eventsRecorded < maxEvents)) {
        (*calendarPtr).incrementYear();
        int d100 = std::rand() % 100;
        if (d100 < 95) {
            continue;
        }
        else {
            // grab the 2 manually initialised regions and start a war between them
            std::vector<Region*> allies = {&(*regionsPtr)[0]};
            std::vector<Region*> axis = {&(*regionsPtr)[1]};
            War thisWar(allies, axis);
            thisWar.startWar((*calendarPtr).currentYear);
            (*ledgerPtr).recordEvent(thisWar);
        }
    }
}
