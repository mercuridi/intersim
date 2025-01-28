// guard
#ifndef LEDGER_HPP_
#define LEDGER_HPP_

// library imports
#include <vector>

// header imports
#include "events.hpp"
#include "date.hpp"

class Ledger {
    public:
        std::vector<Event> events;
        Ledger(Date *calendarPtr);
        void recordEvent(Event event);
        int getNextID();
        int getEventsRecorded();
        void printLedger(int maxYear);
    private:
        // variables
        int eventsRecorded;
        int idCount;
        Date *calendarPtr;

        // functions
};

// end guard
#endif // LEDGER_HPP_
