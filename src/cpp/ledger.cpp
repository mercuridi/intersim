#include <vector>
#include <format>

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
        // long print statement:
        std::cout << i+1 << ": " << // event number - maybe record this in ledger as an ID?
        Ledger::events[i].summary << // event summary
        std::format("It happened in the year {}", Ledger::events[i].year) << // event year
        "\n";
    }
    std::cout << "Final year: " << (*calendarPtr).currentYear << "\n";
}