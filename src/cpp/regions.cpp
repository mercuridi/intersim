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