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
    ledger.printLedger();
    std::cout << "Dummy event recorded and printed\n";
    Region dokerraReg("Dokerra", -10);
    Region naranciaReg("Narancia", 10);
    std::vector<Region> regions = {dokerraReg, naranciaReg};
    std::cout << "Regions initialised\n";
    Calendar calendar(0);
    std::cout << "Calendar initialised\n";
    Director director(&calendar, &ledger, &regions);
    std::cout << "Director initialised\n";
    std::cout << "Calculating history...\n";
    director.calculateHistory(100);
    return 0;
};