// guard
#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_

// library imports
#include <iostream>
#include <unordered_map>

class Calendar {
    public:
        Calendar();
        int getYearLength();
        int getWeekLength();
        int getMonthsInYear();
        int getLeapDays(int yearIndex);
        int getDaysInMonth(int monthIndex);
        std::string getDayName(int dayIndex);
        std::string getMonthName(int monthIndex);
    private:
        int yearLength;
        int weekLength;
        int monthsInYear;
        std::unordered_map<int, int> leapDays;
        std::unordered_map<int, int> daysInMonth;
        std::unordered_map<int, std::string> dayNames;
        std::unordered_map<int, std::string> monthNames;
};

// end guard
#endif // CALENDAR_HPP_