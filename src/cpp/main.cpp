// library imports
#include <iostream>
#include <vector>
#include <format>

// header imports
#include "../hpp/calendar.hpp"
#include "../hpp/director.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"
#include "../hpp/main.hpp"
#include "../hpp/regions.hpp"

int main() {
    // initialise program
    std::cout << "Program initialised\n";
    std::cout << "C++ version " << __cplusplus << "\n";

    // initialise calendar (used by ledger and director)
    Calendar calendar(0);
    std::cout << "Calendar initialised\n";

    // basic functionality check for:
    // 1. initialising the ledger (used by director)
    // 2. recording an event to the ledger
    Ledger ledger(&calendar);
    Event dummyEvent;
    ledger.recordEvent(dummyEvent);
    ledger.printLedger();
    std::cout << "Dummy event recorded and printed\n";

    // initialise some regions manually (used by director)
    Region testReg1("Test Region 1", -10);
    Region testReg2("Test Region 2", 10);
    std::vector<Region> regions = {testReg1, testReg2};
    std::cout << "Regions initialised\n";

    // initialise director
    Director director(&calendar, &ledger, &regions);
    std::cout << "Director initialised\n";

    // call primary loop
    std::cout << "Calculating history...\n";
    director.calculateHistory(100, 5);
    std::cout << "Main executed\n";

    ledger.printLedger();
    return 0;
};