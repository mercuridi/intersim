// library imports
#include <iostream>
#include <string>
#include <format>

// header imports
#include "../hpp/regions.hpp"
#include "../hpp/ledger.hpp"
#include "../hpp/events.hpp"

// change in future to use a date representation instead of just a year
// event constructor
Event::Event(int year, int numericID, std::string summary) {
    this->year = year;
    this->numericID = numericID;
    this->summary = summary;
};

// war subclass constructor
War::War(std::vector<Region*> allies, std::vector<Region*> axis, int year, int numericID, std::string summary) : Event(year, numericID, summary) {
    this->allies = allies;
    this->axis = axis;
};

// function to start a war after it's been defined
void War::startWar(int startYear) {
    // add a guard in case the war is already started
    this->ongoing = true;
    //this->year = startYear;
}

// function to end a war after it's been defined
void War::endWar(int endYear, std::vector<Region*>* winners, std::vector<Region*>* losers) {
    // add a guard in case the war hasn't started yet
    this->ongoing = false;
    this->endYear = endYear;
    this->winners = winners;
    this->losers = losers;
    this->summary = std::format("This war began in {} and ended in {}.", year, endYear);
}

// function to print out the details of any given war
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