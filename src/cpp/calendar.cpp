// library imports
#include <iostream>
#include <vector>

// header imports
#include "../hpp/calendar.hpp"

// calendar constructor
Calendar::Calendar(int startYear) {
    currentYear = startYear;
};

// function to print the current date
void Calendar::printCurrentDate() {
    std::cout << currentYear << "\n";
};

// function to increment the year
void Calendar::incrementYear() {
    currentYear++;
    //printCurrentDate();
};