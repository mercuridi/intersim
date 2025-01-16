#include <vector>

#include "../hpp/calendar.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"


Ledger::Ledger(Calendar *calendarPtr) {
    eventsRecorded = 0;
    this->calendarPtr = calendarPtr;
};

void Ledger::recordEvent(Event event) {
    Ledger::events.push_back(event);
    eventsRecorded++;
};

void Ledger::printLedger() {
    // this function prints the ENTIRE ledger!
    // printing long ledgers will probably crash
    // this function may change to only print a selection of events?
    for (int i = 0; i < events.size(); i++) {
        std::cout << i+1 << ": " << Ledger::events[i].summary << "\n";
    }
    std::cout << "Final year: " << (*calendarPtr).currentYear << "\n";
}