// guard
#ifndef DATE_HPP_
#define DATE_HPP_

// library imports
#include <iostream>
#include <limits.h>

class Date {
    public: 
        Date(int year = INT_MAX, int month = INT_MAX, int day = INT_MAX);
        int getYear();
        int getMonth();
        int getDay();
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
};

// end guard
#endif // DATE_HPP_
