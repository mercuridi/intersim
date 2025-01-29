// library imports
#include <iostream>
#include <vector>

// header imports
#include "../hpp/ledger.hpp"
#include "../hpp/events.hpp"
#include "../hpp/director.hpp"
#include "../hpp/date.hpp"
#include "../hpp/calendar.hpp"

// director constructor
Director::Director(Calendar *calendarPtr, Date *todayDatePtr, Ledger *ledgerPtr, std::vector<Region> *regionsPtr) {
    this->calendarPtr   = calendarPtr;
    this->todayDatePtr  = todayDatePtr;
    this->ledgerPtr     = ledgerPtr;
    this->regionsPtr    = regionsPtr;
}

// function to calculate history, pulling everything together
// possibly the most important function of the project
void Director::calculateHistory(int stopYear, int maxEvents) {

    // while we haven't hit the max year or max war events
    while (((*todayDatePtr).getYear() < stopYear) and 
            ((*ledgerPtr).getEventsRecorded() < maxEvents)) {
        
        // on each iteration, increment the day
        (*todayDatePtr).incrementDay();

        // roll a d100
        int d10000 = std::rand() % 10000;
        if (d10000 < 9990) {
            continue;
        }
        // on rare occasions, begin a war
        else {
            // grab the 2 manually initialised regions and start a war between them
            std::vector<Region*> allies = {&(*regionsPtr)[0]};
            std::vector<Region*> axis = {&(*regionsPtr)[1]};
            War thisWar(allies, axis, Date(calendarPtr, (*todayDatePtr).getDay(), (*todayDatePtr).getMonth(), (*todayDatePtr).getYear()), (*ledgerPtr).getNextID(), "This is a dummy war made as part of testing.");
            thisWar.startWar((*todayDatePtr).getYear());
            (*ledgerPtr).recordEvent(thisWar);
        }
    }
}
