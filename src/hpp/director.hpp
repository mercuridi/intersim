// guard
#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

// header imports
#include "../hpp/date.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"

class Director {
    public:
        Director(Date *calRef, Ledger *ledRef, std::vector<Region> *regionsRef);
        void calculateHistory(int stopYear, int maxEvents);
    private:
        Date *calendarPtr;
        Ledger *ledgerPtr;
        std::vector<Region> *regionsPtr;


};

// end guard
#endif // DIRECTOR_HPP_
