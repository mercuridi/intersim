// library imports
#include <iostream>

// header imports
#include "../hpp/calendar.hpp"

Calendar::Calendar() {
    // hard coded values for narancian calendar
    // eventually, have these dynamically constructed from some config
    // ideally, support https://fantasy-calendar.com/
    this->yearLength = 182;
    this->weekLength = 7;
    this->monthsInYear = 6;
    this->leapDays[2] = 14;
    this->daysInMonth[0] = 29;
    this->daysInMonth[1] = 37;
    this->daysInMonth[2] = 34;
    this->daysInMonth[3] = 31;
    this->daysInMonth[4] = 28;
    this->daysInMonth[5] = 23;
    this->monthNames[0] = std::string("Akrival");
    this->monthNames[1] = std::string("Vetral");
    this->monthNames[2] = std::string("Kiivaskal");
    this->monthNames[3] = std::string("Trakettal");
    this->monthNames[4] = std::string("Eruvettal");
    this->monthNames[5] = std::string("Elimal");
    this->dayNames[0] = std::string("Trenum");
    this->dayNames[1] = std::string("Fizum");
    this->dayNames[2] = std::string("Zyntymum");
    this->dayNames[3] = std::string("Ambardum");
    this->dayNames[4] = std::string("Iptum");
    this->dayNames[5] = std::string("Kannakanum");
    this->dayNames[6] = std::string("Tuntijum");
}

int Calendar::getYearLength() {
    return yearLength;
}

int Calendar::getWeekLength() {
    return weekLength;
}

int Calendar::getMonthsInYear() {
    return monthsInYear;
}

int Calendar::getLeapDays(int yearIndex) {
    return leapDays[yearIndex];
}

int Calendar::getDaysInMonth(int monthIndex) {
    return daysInMonth[monthIndex];
}

std::string Calendar::getDayName(int dayIndex) {
    return dayNames[dayIndex];
}

std::string Calendar::getMonthName(int monthIndex) {
    return monthNames[monthIndex];
}