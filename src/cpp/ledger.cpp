// library imports
#include <vector>
#include <format>

// header imports
#include "../hpp/calendar.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"

// ledger constructor
Ledger::Ledger(Calendar *calendarPtr) {
    events;
    eventsRecorded = 0;
    idCount = 0;
    this->calendarPtr = calendarPtr;
};

// function to record an event (works for event subclasses)
void Ledger::recordEvent(Event event) {
    Ledger::events.push_back(event);

    // increment the number of events recorded
    eventsRecorded++;
};

int Ledger::getNextID() {
    idCount++;
    return idCount;
}

// this function prints the ledger
void Ledger::printLedger() {
    // printing long ledgers will probably crash
    // this function may change to only print a selection of events?
    for (int i = 0; i < events.size(); i++) {
        // long print statement:
        std::cout <<
        Ledger::events[i].numericID << ": " << // event ID
        Ledger::events[i].summary << // event summary
        std::format(" It happened in the year {}", Ledger::events[i].year) << // event year
        ".\n";
    }
    std::cout << "Final year: " << (*calendarPtr).currentYear << "\n";
}