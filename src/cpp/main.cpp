// library imports
#include <iostream>
#include <vector>
#include <format>

// header imports
#include "../hpp/calendar.hpp"
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

    // initialise calendar (used by all date objects)
    Calendar calendar;
    std::cout << "Calendar initialised\n";

    // initialise todayDate (used by ledger and director)
    Date todayDate(&calendar, 0, 0, 0);
    std::cout << "todayDate initialised\n";

    // Initialise event ledger (used by director)
    Ledger ledger(&todayDate);
    std::cout << "Ledger initialised\n";

    // manual event recordings for whatever reason
    // currently used for testing the written day finder (date.cpp)
    //ledger.recordEvent(Event(Date(10, 6, 6), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(1, 5, 5), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(10, 4, 4), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(1, 2, 3), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(1, 1, 2), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(23, 6, 1), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(10, 3, 1), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(1, 3, 1), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(10, 2, 1), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(1, 2, 1), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(20, 1, 1), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(10, 1, 1), ledger.getNextID()));
    //ledger.recordEvent(Event(Date(1, 1, 1), ledger.getNextID()));

    // initialise some regions manually (used by director)
    Region testReg1("Test Region 1", 0);
    Region testReg2("Test Region 2", 0);
    std::vector<Region> regions = {testReg1, testReg2};
    std::cout << "Test regions initialised\n";

    // initialise director
    Director director(&calendar, &todayDate, &ledger, &regions);
    std::cout << "Director initialised\n";

    // call primary loop
    std::cout << "Calculating history...\n";
    int maxYear = 1000;
    int maxEvents = 200;
    director.calculateHistory(maxYear, maxEvents);

    // request ledger print to terminal
    std::cout << "Requesting ledger print...\n";
    ledger.printLedger(maxYear);

    // finish program, shutdown gracefully
    std::cout << "Main executed, returning 0.\n";
    return 0;
};