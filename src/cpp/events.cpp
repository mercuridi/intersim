#include <iostream>
#include <string>

#include "../hpp/regions.hpp"
#include "../hpp/events.hpp"

// change in future to use a date representation instead of a year
Event::Event(int year, std::string summary) {
    this->year = year;
    this->summary = summary;
};

War::War(std::vector<Region*> allies, std::vector<Region*> axis) : Event(){
    this->allies = allies;
    this->axis = axis;
};

void War::startWar(int startYear) {
    this->ongoing = true;
    this->year = startYear;
}

void War::endWar(int endYear, std::vector<Region*>* winners, std::vector<Region*>* losers) {
    this->ongoing = false;
    this->endYear = endYear;
    this->winners = winners;
    this->losers = losers;
}

void War::printWar() {
    std::cout << "Allies: ";
    for (int i = 0; i < allies.size(); i++) {
        std::cout << i+1 << ": " << (*allies[i]).name << "\n";
    }
    std::cout << "Axis: ";
    for (int i = 0; i < allies.size(); i++) {
        std::cout << i+1 << ": " << (*axis[i]).name << "\n";
    }
    std::cout << "Start year: " << year << "\n";
    std::cout << "End year: " << endYear << "\n";
}