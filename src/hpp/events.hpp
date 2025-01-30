// guard
#ifndef EVENTS_HPP_
#define EVENTS_HPP_

// library imports
#include <iostream>
#include <vector>
#include <string>
#include <climits>

// header imports
#include "date.hpp"
#include "regions.hpp"

class Event {
    public: 
        Event(Date eventDate, int numericID, std::string summary);
        Date getEventDateObj();
        int getEventID();
        std::string getSummary();
    private:
        // change in future to use a date representation instead of a year
        Date eventDateObj;
        int numericID;
        std::string summary;
    protected:
        void setSummary(std::string newSummary);
};

class War: public Event {
    public:
        War( // inherits from event in .cpp
            std::vector<Region*> allies, 
            std::vector<Region*> axis, 
            Date eventDate, 
            int numericID, 
            std::string summary); 
        void startWar(int startYear);
        void endWar(
            Date endDate, 
            std::vector<Region*>* winners, 
            std::vector<Region*>* losers);
        void printWar();
    private:
        std::vector<Region*> allies;
        std::vector<Region*> axis;
        Date endDate;
        bool ongoing;
        std::vector<Region*>* winners;
        std::vector<Region*>* losers;
};

// end guard
#endif // EVENTS_HPP_
