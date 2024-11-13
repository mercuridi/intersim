#include <vector>

#include "../hpp/events.hpp"

class Ledger {
    public:
        std::vector<Event> events;
        Ledger() {};
        void recordEvent(Event event) {
            Ledger::events.push_back(event);
        };
        void printLedger() {
            for (int i = 0; i < events.size(); i++) {
                std::cout << Ledger::events[i].summary << "\n";
            }
        }
};