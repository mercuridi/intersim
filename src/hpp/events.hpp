#ifndef EVENTS_HPP_
#define EVENTS_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include "regions.hpp"

class Event {
    public:
        // change in future to use a date representation instead of a year
        int year;
        std::string summary;
        Event(int year = INT_MAX, std::string summary = "This event has no provided summary.");
};

class War: public Event {
    public:
        std::vector<Region*> allies;
        std::vector<Region*> axis;
        // start year inherited from base class
        int endYear;
        bool ongoing;
        std::vector<Region*>* winners;
        std::vector<Region*>* losers;

        War(std::vector<Region*> allies, std::vector<Region*> axis); // inherits from event in .cpp
        void startWar(int startYear);
        void endWar(int endYear, std::vector<Region*>* winners, std::vector<Region*>* losers);
        void printWar();
};

#endif // EVENTS_HPP_
