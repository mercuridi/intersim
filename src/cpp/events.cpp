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

int Event::getEventYear() {
    return this->year;
}

int Event::getEventID() {
    return this->numericID;
}

std::string Event::getSummary() {
    return this->summary;
}

void Event::setSummary(std::string newSummary) {
    this->summary = newSummary;
}

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
    this->setSummary(std::format("This war began in {} and ended in {}.", this->getEventYear(), endYear));
}

// function to print out the details of any given war
void War::printWar() {
    std::cout << "Allies: ";
    for (int i = 0; i < allies.size(); i++) {
        std::cout << i+1 << ": " << (*allies[i]).getRegionName() << "\n";
    }
    std::cout << "Axis: ";
    for (int i = 0; i < allies.size(); i++) {
        std::cout << i+1 << ": " << (*axis[i]).getRegionName() << "\n";
    }
    std::cout << "Start year: " << this->getEventYear() << "\n";
    std::cout << "End year: " << endYear << "\n";
}