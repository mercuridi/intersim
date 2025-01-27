// library imports
#include <iostream>
#include <vector>
#include <string>

// header imports
#include "../hpp/date.hpp"

// Date constructor
Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
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

// function to print the current date
std::string Date::getDateNumeric() {
    return
        std::to_string(getDay()) + "/" +
        std::to_string(getMonth()) + "/" +
        std::to_string(getYear());
};

// function to increment the year
void Date::incrementYear() {
    year++;
};

// function to increment the month

// function to increment the day