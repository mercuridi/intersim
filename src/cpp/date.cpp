// library imports
#include <iostream>
#include <vector>
#include <string>

// header imports
#include "../hpp/date.hpp"

// Date constructor
Date::Date(int day, int month, int year) {
    this->year = year;
    this->month = month;
    this->day = day;

    // hard coded values for the Narancian calendar
    // ideally, move these so they're somehow accessible without
    // being written to every single date object known to man
    // is it possible to make these const in header?
    this->yearLength = 182;
    this->weekLength = 7;
    this->monthsInYear = 6;
    this->leapDays[2] = 14;
    this->daysInMonth[1] = 29;
    this->daysInMonth[2] = 37;
    this->daysInMonth[3] = 34;
    this->daysInMonth[4] = 31;
    this->daysInMonth[5] = 28;
    this->daysInMonth[6] = 23;
    this->monthNames[1] = std::string("Akrival");
    this->monthNames[2] = std::string("Vetral");
    this->monthNames[3] = std::string("Kiivaskal");
    this->monthNames[4] = std::string("Trakettal");
    this->monthNames[5] = std::string("Eruvettal");
    this->monthNames[6] = std::string("Elimal");
    this->dayNames[1] = std::string("Fizum");
    this->dayNames[2] = std::string("Zyntymum");
    this->dayNames[3] = std::string("Ambardum");
    this->dayNames[4] = std::string("Iptum");
    this->dayNames[5] = std::string("Kannakanum");
    this->dayNames[6] = std::string("Tuntijium");
    this->dayNames[7] = std::string("Trenum");
};

int Date::getYear() {
    return this->year;
}

int Date::getMonth() {
    return this->month;
}

int Date::getDay() {
    return this->day;
}

int Date::getDayOfWeek() {
    int daysSinceFirstDay = 0;
    int firstDay = 6;
    int localYear = year;
    int localMonth = month;
    int localDay = day;
    // figure out a more reliable way to calculate days added from leap years
    int leapYears = localYear / 2;
    daysSinceFirstDay = daysSinceFirstDay + (leapDays[2] * leapYears);
    std::cout << daysSinceFirstDay << " (start)\n";
    while (localDay != 1) {
        daysSinceFirstDay++;
        localDay--;
    }
    std::cout << daysSinceFirstDay << " (days added)\n";
    while (localMonth != 1) {
        daysSinceFirstDay = daysSinceFirstDay + daysInMonth[localMonth-1];
        localMonth--;
    }
    std::cout << daysSinceFirstDay << " (months added)\n";
    while (localYear != 1) {
        daysSinceFirstDay = daysSinceFirstDay + yearLength;
        localYear--;
    }
    std::cout << daysSinceFirstDay << " (years added)\n";
    daysSinceFirstDay = daysSinceFirstDay + firstDay;
    daysSinceFirstDay = (daysSinceFirstDay % 7) + 1;
    std::cout << daysSinceFirstDay << " (final answer)\n";
    return daysSinceFirstDay;
}

std::string Date::getDayOfWeekName() {
    return dayNames[getDayOfWeek()];
}

std::string Date::getDateWritten() {
    std::string dayQual;
    if (((day == 11) or (day == 12)) or (day == 13)) {
        dayQual = "th";
    }
    else if (day % 10 == 1) {
        dayQual = "st";
    }
    else if (day % 10 == 2) {
        dayQual = "nd";
    }
    else if (day % 10 == 3) {
        dayQual = "rd";
    }
    else {
        dayQual = "th";
    }
    return
        getDayOfWeekName() + " the " +
        std::to_string(day) + dayQual + " of " +
        monthNames[month] + ", " +
        std::to_string(year);
}

// function to print the current date
std::string Date::getDateNumeric() {
    return
        std::to_string(getDay()) + "/" +
        std::to_string(getMonth()) + "/" +
        std::to_string(getYear());
}

// function to increment the year
void Date::incrementYear() {
    year++;
}

// function to increment the month
void Date::incrementMonth() {
    month++;
    if (month > monthsInYear) {
        month = 1;
        incrementYear();
    }
}

// function to increment the day
void Date::incrementDay() {
    day++;
    if (day > daysInMonth[month]) {
        day = 1;
        incrementMonth();
    }
}