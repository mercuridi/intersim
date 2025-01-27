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

int Ledger::getEventsRecorded() {
    return this->eventsRecorded;
}

// function to get a new unique ID for a generated token
int Ledger::getNextID() {
    idCount++;
    return idCount;
}

// this function prints the entire ledger
void Ledger::printLedger() {
    // printing long ledgers will probably crash
    // this function may change to only print a selection of events?
    std::cout << "\nFull ledger print requested...\n";
    for (int i = 0; i < events.size(); i++) {
        // the following lines are a single long print statement:
        std::cout <<
        Ledger::events[i].getEventID() << ": " << // event ID
        Ledger::events[i].getSummary() << // event summary
        std::format(" It happened in the year {}", Ledger::events[i].getEventYear()) << // event year
        ".\n";
    }
    std::cout << "Final year: " << (*calendarPtr).getCurrentYear() << "\n\n";
}