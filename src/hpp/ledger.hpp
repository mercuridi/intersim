#ifndef LEDGER_HPP_
#define LEDGER_HPP_

#include <vector>

#include "events.hpp"

class Ledger {
    public:
        std::vector<Event> events;
        Ledger();
        void recordEvent(Event event);
        void printLedger();
};

#endif // LEDGER_HPP_
