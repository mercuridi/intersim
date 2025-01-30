// library imports
#include <iostream>

// header imports
#include "../hpp/regions.hpp"

// region constructor
Region::Region(std::string name, int attitude) {
    // for now, attitude as a singular integer representation
    // in future, improve logic to handle full attitude matrices
    this->name = name;
    this->attitude = attitude;
}

int Region::getAttitude() {
    return attitude;
}

std::string Region::getRegionName() {
    return this->name;
}

void Region::setAttitude(int newAttitude) {
    attitude = newAttitude;
}

void Region::nudgeAttitudeRandom(int warThres) {
    int maxAttitude = warThres * 2;
    int maxNudge = 10;
    int random = std::rand() % maxNudge;
    if (attitude > maxAttitude) {
        attitude = attitude - 10 * random;
    }
    else if (attitude < -maxAttitude) {
        attitude = attitude + 10 * random;
    }
    else if ((std::rand() % 2) == 0) {
        attitude = attitude - random;
    }
    else {
        attitude = attitude + random;
    }
}