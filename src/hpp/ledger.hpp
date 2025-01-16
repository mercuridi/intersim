#ifndef LEDGER_HPP_
#define LEDGER_HPP_

#include <vector>

#include "events.hpp"
#include "calendar.hpp"

class Ledger {
    public:
        // variables
        int eventsRecorded;
        Calendar *calendarPtr;

        // functions
        std::vector<Event> events;
        Ledger(Calendar *calendarPtr);
        void recordEvent(Event event);
        void printLedger();
};

#endif // LEDGER_HPP_
