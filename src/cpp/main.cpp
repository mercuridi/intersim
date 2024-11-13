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
    std::cout << __cplusplus;
    std::cout << "\nStarting program\n";
    Ledger ledger;
    std::cout << "Ledger created\n";
    Event event;
    std::cout << "Event created\n";
    ledger.recordEvent(event);
    ledger.recordEvent(event);
    ledger.recordEvent(event);
    std::cout << "Events recorded in ledger\n";
    ledger.printLedger();
    std::cout << "Ending program\n";
    return 0;
};