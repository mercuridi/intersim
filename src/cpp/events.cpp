#include <iostream>
#include <vector>
#include <format>

#include "../hpp/regions.hpp"

class Event {
    public:
        // change in future to use a date representation instead of a year
        int year;
        std::string summary;
        Event(int year=900) {
            this->year = year;
            summary = std::format("This is a dummy event that occurred in the year {}", year);
        };
};

class War: public Event {
    public:
        Region attacker;
        Region defender;
        Region winner;
        Region loser;
        War(Region attacker, Region defender) {
            this->attacker = attacker;
            this->defender = defender;
        };
};