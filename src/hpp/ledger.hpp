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
        std::vector<Event> events;
        Ledger(Calendar *calendarPtr);
        void recordEvent(Event event);
        int getNextID();
        int getEventsRecorded();
        void printLedger();
    private:
        // variables
        int eventsRecorded;
        int idCount;
        Calendar *calendarPtr;

        // functions
};

// end guard
#endif // LEDGER_HPP_
