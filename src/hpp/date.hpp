// guard
#ifndef DATE_HPP_
#define DATE_HPP_

// library imports
#include <iostream>
#include <climits>

// header imports
#include "../hpp/calendar.hpp"

class Date {
    public: 
        Date(int day = INT_MAX, int month = INT_MAX, int year = INT_MAX);
        Date(Calendar* calendarPtr, int day, int month, int year);
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
        Calendar *calendarPtr;
        int year;
        int month;
        int day;
};

// end guard
#endif // DATE_HPP_
