// guard
#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

// header imports
#include "../hpp/date.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"

class Director {
    public:
        Director(
            Calendar *calendarPtr, 
            Date *todayPtr, 
            Ledger *ledPtr, 
            std::vector<Region> *regionsPtr);
        void calculateHistory(int stopYear, int maxEvents);
    private:
        Calendar *calendarPtr;
        Date *todayDatePtr;
        Ledger *ledgerPtr;
        std::vector<Region> *regionsPtr;
};

// end guard
#endif // DIRECTOR_HPP_
