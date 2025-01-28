// guard
#ifndef DATE_HPP_
#define DATE_HPP_

// library imports
#include <iostream>
#include <limits.h>
#include <unordered_map>

class Date {
    public: 
        Date(int day = INT_MAX, int month = INT_MAX, int year = INT_MAX);
        int getYear();
        int getMonth();
        int getDay();
        int getDayOfWeek();
        std::string getDayOfWeekName();
        std::string getMonthName();
        std::string getDateNumeric();
        std::string getDateWritten();
        void incrementYear();
        void incrementMonth();
        void incrementDay();
    private:
        // calendar keeps track of "today" in the simulation
        int year;
        int month;
        int day;

        // the date object also knows how many days in each month and how many months in each year
        // along with names for each, where they exist
        // hard coded for now, eventually move this to its own logic to read from some kind of config file
        // extremely memory inefficient - perhaps create singleton to hold the data and pass a reference to it here?
        int yearLength;
        int weekLength;
        int monthsInYear;
        std::unordered_map<int, int> leapDays;
        std::unordered_map<int, int> daysInMonth;
        std::unordered_map<int, std::string> dayNames;
        std::unordered_map<int, std::string> monthNames;
};

// end guard
#endif // DATE_HPP_
