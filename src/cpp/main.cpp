#include <iostream>
#include <vector>
#include <format>

#include "../hpp/calendar.hpp"
#include "../hpp/director.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"
#include "../hpp/main.hpp"
#include "../hpp/regions.hpp"

int main() {
    std::cout << "C++ version " << __cplusplus << "\n";
    Ledger ledger;
    Event event;
    ledger.recordEvent(event);
    ledger.recordEvent(event);
    ledger.recordEvent(event);
    ledger.printLedger();
    return 0;
};