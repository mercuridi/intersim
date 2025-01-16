// guard
#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_

class Calendar {
    public:
        // later, improve to add granularity to the calendar
        // years is good enough for early development
        int currentYear;
        Calendar(int startYear);
        void printCurrentDate();
        void incrementYear();
};

// end guard
#endif // CALENDAR_HPP_
