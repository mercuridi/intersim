#ifndef EVENTS_HPP_
#define EVENTS_HPP_

#include "regions.hpp"

class Event {
    public:
        // change in future to use a date representation instead of a year
        int year;
        std::string summary;
        Event(int year=900);
};

class War: public Event {
    public:
        Region attacker;
        Region defender;
        Region winner;
        Region loser;
        War(Region attacker, Region defender);
};

#endif // EVENTS_HPP_
