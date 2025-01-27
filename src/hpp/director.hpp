// guard
#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

// header imports
#include "../hpp/calendar.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"

class Director {
    public:
        Director(Calendar *calRef, Ledger *ledRef, std::vector<Region> *regionsRef);
        void calculateHistory(int stopYear, int maxEvents);
    private:
        Calendar *calendarPtr;
        Ledger *ledgerPtr;
        std::vector<Region> *regionsPtr;


};

// end guard
#endif // DIRECTOR_HPP_
