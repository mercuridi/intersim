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
Director::Director(
        Calendar *calendarPtr, 
        Date *todayDatePtr, 
        Ledger *ledgerPtr, 
        std::vector<Region> *regionsPtr) {
    this->calendarPtr   = calendarPtr;
    this->todayDatePtr  = todayDatePtr;
    this->ledgerPtr     = ledgerPtr;
    this->regionsPtr    = regionsPtr;
}

// function to calculate history, pulling everything together
// possibly the most important function of the project
void Director::calculateHistory(int stopYear, int maxEvents) {
    int warThreshold = 200;
    // while we haven't hit the max year or max war events
    while (((*todayDatePtr).getYear() < stopYear) and 
            ((*ledgerPtr).getEventsRecorded() < maxEvents)) {
        
        // on each iteration, increment the day
        (*todayDatePtr).incrementDay();

        // nudge the two regions' attitudes
        (*regionsPtr)[0].nudgeAttitudeRandom(warThreshold);
        (*regionsPtr)[1].nudgeAttitudeRandom(warThreshold);

        // on rare occasions, when attitudes are too far apart, begin a war
        if (abs( // absolute difference of attitudes
            ((*regionsPtr)[0].getAttitude() - (*regionsPtr)[1].getAttitude())) 
                > warThreshold) {

            // reset attitudes to 0
            (*regionsPtr)[0].setAttitude(0);
            (*regionsPtr)[1].setAttitude(0);

            // grab the 2 initialised regions and start a war between them
            std::vector<Region*> allies = {&(*regionsPtr)[0]};
            std::vector<Region*> axis = {&(*regionsPtr)[1]};
            War thisWar(
                allies, axis, 
                Date( // date object construction in constructor call
                    calendarPtr, 
                    (*todayDatePtr).getDay(), 
                    (*todayDatePtr).getMonth(), 
                    (*todayDatePtr).getYear()), 
                (*ledgerPtr).getNextID(), 
                "This is a dummy war made as part of testing.");
            thisWar.startWar((*todayDatePtr).getYear());
            (*ledgerPtr).recordEvent(thisWar);
        }
    }
    // loop can end for 2 reasons:
    // - stopYear reached
    // - maxEvents reached
    // print a note so we know which one stopped the loop
    if ((*todayDatePtr).getYear() < stopYear) {
        std::cout << "stopYear reached.\n";
    }
    else if ((*ledgerPtr).getEventsRecorded() < maxEvents) {
        std::cout << "maxEvents reached.\n";
    }
}
