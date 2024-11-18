#include <vector>

#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"


Ledger::Ledger() {};
void Ledger::recordEvent(Event event) {
    Ledger::events.push_back(event);
};

void Ledger::printLedger() {
    // this function prints the ENTIRE ledger!
    // printing long ledgers will probably crash
    // this function may change to only print a selection of events?
    for (int i = 0; i < events.size(); i++) {
        std::cout << i+1 << ": " << Ledger::events[i].summary << "\n";
    }
}