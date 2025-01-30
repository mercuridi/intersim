// library imports
#include <vector>
#include <format>
#include <iomanip>

// header imports
#include "../hpp/date.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"

// ledger constructor
Ledger::Ledger(Date *todayDatePtr) {
    events;
    eventsRecorded = 0;
    idCount = 0;
    this->todayDatePtr = todayDatePtr;
};

// function to record an event (works for event subclasses)
void Ledger::recordEvent(Event event) {
    Ledger::events.push_back(event);
    // increment the number of events recorded
    eventsRecorded++;
};

// returns the number of events recorded in total
int Ledger::getEventsRecorded() {
    return this->eventsRecorded;
}

// function to get a new unique ID for a generated token
int Ledger::getNextID() {
    idCount++;
    return idCount;
}

int countDigits(int n) {
    // from https://www.geeksforgeeks.org
    if (n == 0) // Base case
        return 1;
    int count = 0;
    while (n != 0) { // Iterate till n has digits remaining
        n = n / 10; // Remove rightmost digit
        ++count; // Increment digit count by 1
    }
    return count;
}

// this function prints the entire ledger
void Ledger::printLedger(int maxYear) {
    // printing long ledgers might crash
    // this function may change to only print a selection of events?
    std::cout << "\nFull ledger print requested...\n";
    for (int i = 0; i < events.size(); i++) {
        std::cout 
            << std::setw(countDigits(maxYear+2)) 
            << Ledger::events[i].getEventID() 
            << ": "; // no line break
        // above line prints a left-padded event ID
        // below lines print the rest of the event information
        std::cout 
            << Ledger::events[i].getSummary() // summary
            << std::string(" It happened on the date ")
            // written event date
            << Ledger::events[i].getEventDateObj().getDateWritten()
            // numeric event date in brackets
            << " (" 
            << Ledger::events[i].getEventDateObj().getDateNumeric() 
            << ") " 
            << "\n"; 
    }
    std::cout << "Final year: " << (*todayDatePtr).getYear() << "\n\n";
}