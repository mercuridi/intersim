#include <vector>

#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"


Ledger::Ledger() {};
void Ledger::recordEvent(Event event) {
    Ledger::events.push_back(event);
};
void Ledger::printLedger() {
    for (int i = 0; i < events.size(); i++) {
        std::cout << Ledger::events[i].summary << "\n";
    }
}