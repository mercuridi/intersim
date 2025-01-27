// library imports
#include <iostream>
#include <vector>
#include <format>

// header imports
#include "../hpp/date.hpp"
#include "../hpp/director.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"
#include "../hpp/main.hpp"
#include "../hpp/regions.hpp"

int main() {
    // initialise program
    std::cout << "\nProgram initialised\n";
    std::cout << "C++ version " << __cplusplus << "\n\n";

    // initialise calendar (used by ledger and director)
    Date calendar(0, 0, 0);
    std::cout << "Calendar initialised\n";

    // Initialise event ledger (used by director)
    Ledger ledger(&calendar);
    std::cout << "Ledger initialised\n";

    // manual event recordings for whatever reason
    // currently used for testing the written day finder (date.cpp)
    ledger.recordEvent(Event(Date(1, 1, 1), ledger.getNextID()));
    ledger.recordEvent(Event(Date(10, 1, 1), ledger.getNextID()));
    ledger.recordEvent(Event(Date(1, 2, 1), ledger.getNextID()));
    ledger.recordEvent(Event(Date(10, 2, 1), ledger.getNextID()));
    ledger.recordEvent(Event(Date(1, 4, 1), ledger.getNextID()));
    
    std::cout << "Dummy event recorded\n";

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
    director.calculateHistory(1, 20);

    // request ledger print to terminal
    std::cout << "Requesting ledger print...\n";
    ledger.printLedger();

    // finish program, shutdown gracefully
    std::cout << "Main executed, returning 0.\n";
    return 0;
};