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
    Event dummyEvent;
    ledger.recordEvent(dummyEvent);
    Region dokerra("Dokerra", -10);
    Region naranciaRegion("Narancia", 10);
    ledger.printLedger();
    Calendar calendar(0);
    Director director(calendar);
    director.calculateHistory(100);
    return 0;
};