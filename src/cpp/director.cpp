// library imports
#include <iostream>
#include <vector>

// header imports
#include "../hpp/ledger.hpp"
#include "../hpp/events.hpp"
#include "../hpp/director.hpp"
#include "../hpp/calendar.hpp"

// director constructor
Director::Director(Calendar *calendarPtr, Ledger *ledgerPtr, std::vector<Region> *regionsPtr) {
    this->calendarPtr   = calendarPtr;
    this->ledgerPtr     = ledgerPtr;
    this->regionsPtr    = regionsPtr;
}

// function to calculate history, pulling everything together
// possibly the most important function of the project
void Director::calculateHistory(int stopYear, int maxEvents) {

    // while we haven't hit the max year or max war events
    while (((*calendarPtr).currentYear < stopYear) and 
            ((*ledgerPtr).eventsRecorded < maxEvents)) {
        
        // on each iteration, increment the year
        (*calendarPtr).incrementYear();

        // roll a d100
        int d100 = std::rand() % 100;
        if (d100 < 95) {
            continue;
        }
        // on rare occasions, begin a war
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
