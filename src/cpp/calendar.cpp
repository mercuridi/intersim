#include <iostream>
#include <vector>

#include "../hpp/calendar.hpp"

// later, improve to add granularity to the calendar
// years is good enough for early development
int currentYear;

Calendar::Calendar(int startYear) {
    currentYear = startYear;
};

void Calendar::printCurrentDate() {
    std::cout << currentYear;
    std::cout << "\n";
};

void Calendar::incrementYear() {
    currentYear++;
    //printCurrentDate();
};