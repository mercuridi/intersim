// guard
#ifndef LEDGER_HPP_
#define LEDGER_HPP_

// library imports
#include <vector>

// header imports
#include "events.hpp"
#include "calendar.hpp"

class Ledger {
    public:
        // variables
        int eventsRecorded;
        int idCount;
        Calendar *calendarPtr;

        // functions
        std::vector<Event> events;
        Ledger(Calendar *calendarPtr);
        void recordEvent(Event event);
        int getNextID();
        void printLedger();
};

// end guard
#endif // LEDGER_HPP_
