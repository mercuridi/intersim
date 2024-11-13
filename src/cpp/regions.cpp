#include <iostream>

#include "../hpp/regions.hpp"

// for now, attitude as a singular representation
// in future, improve logic to handle full attitude matrices
Region::Region(std::string name, int attitude) {
    this->name = name;
    this->attitude = attitude;
}