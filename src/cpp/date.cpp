// library imports
#include <iostream>
#include <vector>
#include <string>

// header imports
#include "../hpp/date.hpp"
#include "../hpp/calendar.hpp"

// Date constructor
Date::Date(Calendar *calendarPtr, int day, int month, int year) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->calendarPtr = calendarPtr;
};

Date::Date(int day, int month, int year) {
    // if you're using this constructor on purpose,
    // i assume you know what you're doing
    this->year = year;
    this->month = month;
    this->day = day;
}

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
    // this logic i think actually works? except for missing leap year logic
    // which i really don't want to do right now
    // problem for future me; it works for the interim and 
    // that's all that actually matters right now
    // DO NOT FORGET TO REWRITE void Date::incrementDay() for leap years
    int daysSinceFirstDay = 0; // init tracker
    daysSinceFirstDay = daysSinceFirstDay + day - 1; // add the days that have passed in the month
    daysSinceFirstDay = daysSinceFirstDay + ((year-1)*(*calendarPtr).getYearLength()); // add the days from previous years
    int monthsSinceFirstDay = month; // take val to iterate on
    while (monthsSinceFirstDay > 1) { // months have varying lengths
        daysSinceFirstDay = daysSinceFirstDay + 
            (*calendarPtr).getDaysInMonth((monthsSinceFirstDay-1)%(*calendarPtr).getMonthsInYear());
            // work backwards from the current month, adding all the days in complete months to the tracker
        monthsSinceFirstDay--;
    };
    return daysSinceFirstDay % (*calendarPtr).getWeekLength();
}

std::string Date::getDayOfWeekName() {
    return (*calendarPtr).getDayName(getDayOfWeek());
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
        (*calendarPtr).getMonthName(month-1) + ", " +
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
    if (month > (*calendarPtr).getMonthsInYear()) {
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
    if (day > (*calendarPtr).getDaysInMonth(month)) {
        day = 1;
        incrementMonth();
    }
}