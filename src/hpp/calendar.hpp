// guard
#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_

class Calendar {
    public: 
        Calendar(int startYear);
        int getCurrentYear();
        void printCurrentDate();
        void incrementYear();
    private:
        // later, improve to add granularity to the calendar
        // years is good enough for early development
        int currentYear;
};

// end guard
#endif // CALENDAR_HPP_
