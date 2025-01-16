#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

#include "../hpp/calendar.hpp"
#include "../hpp/events.hpp"
#include "../hpp/ledger.hpp"

class Director {
    public:
        // variables
        Calendar *calendarPtr;
        Ledger *ledgerPtr;
        std::vector<Region> *regionsPtr;

        // functions
        Director(Calendar *calRef, Ledger *ledRef, std::vector<Region> *regionsRef);
        void calculateHistory(int stopYear, int maxEvents);
};
#endif // DIRECTOR_HPP_
