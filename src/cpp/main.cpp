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
    Region dokerraReg("Dokerra", -10);
    Region naranciaReg("Narancia", 10);
    std::vector<Region> regions = {dokerraReg, naranciaReg};
    ledger.printLedger();
    Calendar calendar(0);
    Director director(&calendar, &ledger, &regions);
    director.calculateHistory(100);
    return 0;
};