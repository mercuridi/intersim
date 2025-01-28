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

    // hard coded values for the Narancian/Interim calendar
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
    this->dayNames[6] = std::string("Tuntijium");
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
    // this needs a full rewrite to make it a LOT more robust
    // but only when custom calendars by config are added
    // good luck to whoever takes on the challenge of determining
    // which day of the week it is in fantasy calendars
    // this logic i think actually works except for missing leap year logic
    // which i really don't want to do right now
    // problem for future me; it works for the interim and 
    // that's all that actually matters right now
    // DO NOT FORGET TO REWRITE void Date::incrementDay() for leap years
    int daysSinceFirstDay = 0; // init tracker
    daysSinceFirstDay = daysSinceFirstDay + day - 1; // add the days that have passed in the month
    daysSinceFirstDay = daysSinceFirstDay + ((year-1)*yearLength); // add the days from previous years
    int monthsSinceFirstDay = month; // take val to iterate on
    while (monthsSinceFirstDay > 1) { // months have varying lengths
        daysSinceFirstDay = daysSinceFirstDay + 
            daysInMonth[(monthsSinceFirstDay-1)%monthsInYear];
            // work backwards from the current month, adding all the days in complete months to the tracker
        monthsSinceFirstDay--;
    };
    return daysSinceFirstDay % weekLength;
}

std::string Date::getDayOfWeekName() {
    return dayNames[getDayOfWeek()];
}

std::string Date::getDateWritten() {
    std::string dayOrdinal;
    // is there a better way to do this?
    if (((day == 11) or (day == 12)) or (day == 13)) {
        dayOrdinal = "th";
    }
    else if (day % 10 == 1) {
        dayOrdinal = "st";
    }
    else if (day % 10 == 2) {
        dayOrdinal = "nd";
    }
    else if (day % 10 == 3) {
        dayOrdinal = "rd";
    }
    else {
        dayOrdinal = "th";
    }
    return
        getDayOfWeekName() + " the " +
        std::to_string(day) + dayOrdinal + " of " +
        monthNames[month-1] + ", " +
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
    // TODO: incorporate actual leap year logic to this function
    // lack of leap years isn't actually too important to
    // functionality of the program relative to how fucking annoying
    // it is to implement, so i'll be leaving this for another day a
    // long long time from now (27/01/25)
    day++;
    if (day > daysInMonth[month]) {
        day = 1;
        incrementMonth();
    }
}