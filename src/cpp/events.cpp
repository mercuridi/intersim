#include <iostream>
#include <vector>
#include <format>

#include "../hpp/regions.hpp"
#include "../hpp/events.hpp"

// change in future to use a date representation instead of a year
Event::Event(int year) {
    this->year = year;
    summary = std::format("This is a dummy event that occurred in the year {}", year);
};

War::War(Region attacker, Region defender) {
    this->attacker = attacker;
    this->defender = defender;
};
