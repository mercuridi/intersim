// guard
#ifndef EVENTS_HPP_
#define EVENTS_HPP_

// library imports
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

// header imports
#include "regions.hpp"

class Event {
    public:
        // change in future to use a date representation instead of a year
        int year;
        int numericID;
        std::string summary;
        // default constructor
        Event(int year = INT_MAX, int numericID = INT_MAX, std::string summary = "This event has no provided summary.");
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

        War(std::vector<Region*> allies, std::vector<Region*> axis, int year, int numericID, std::string summary); // inherits from event in .cpp
        void startWar(int startYear);
        void endWar(int endYear, std::vector<Region*>* winners, std::vector<Region*>* losers);
        void printWar();
};

// end guard
#endif // EVENTS_HPP_
