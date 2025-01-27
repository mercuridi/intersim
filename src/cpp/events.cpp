// library imports
#include <iostream>
#include <string>
#include <format>

// header imports
#include "../hpp/regions.hpp"
#include "../hpp/ledger.hpp"
#include "../hpp/events.hpp"

// event constructor
Event::Event(Date eventDate, int numericID, std::string summary) {
    this->eventDateObj = eventDate;
    this->numericID = numericID;
    this->summary = summary;
};

Date Event::getEventDateObj() {
    return this->eventDateObj;
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
void War::endWar(Date endDate, std::vector<Region*>* winners, std::vector<Region*>* losers) {
    // add a guard in case the war hasn't started yet
    this->ongoing = false;
    this->endDate = endDate;
    this->winners = winners;
    this->losers = losers;
    this->setSummary(std::format("This war began in {} and ended in {}.", this->getEventDateObj().getYear(), endDate.getYear()));
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
    std::cout << "Start year: " << this->getEventDateObj().getYear() << "\n";
    std::cout << "End year: " << endDate.getYear() << "\n";
}