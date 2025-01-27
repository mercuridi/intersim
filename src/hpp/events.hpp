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
        Event(int year = INT_MAX, int numericID = INT_MAX, std::string summary = "This event has no provided summary.");
        int getEventYear();
        int getEventID();
        std::string getSummary();
    private:
        // change in future to use a date representation instead of a year
        int year;
        int numericID;
        std::string summary;
    protected:
        void setSummary(std::string newSummary);
};

class War: public Event {
    public:
        War(std::vector<Region*> allies, std::vector<Region*> axis, int year, int numericID, std::string summary); // inherits from event in .cpp
        void startWar(int startYear);
        void endWar(int endYear, std::vector<Region*>* winners, std::vector<Region*>* losers);
        void printWar();
    private:
        std::vector<Region*> allies;
        std::vector<Region*> axis;
        // start year inherited from base class
        int endYear;
        bool ongoing;
        std::vector<Region*>* winners;
        std::vector<Region*>* losers;
};

// end guard
#endif // EVENTS_HPP_
