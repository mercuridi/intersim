#include <iostream>
#include <vector>

class Calendar {
    public:
        // later, improve to add granularity to the calendar
        // years is good enough for early development
        int currentYear;
        Calendar(int startYear) {
            currentYear = startYear;
        }
        void printCurrentDate() {
            std::cout << currentYear;
        };
        void incrementYear() {
            currentYear++;
        }
};