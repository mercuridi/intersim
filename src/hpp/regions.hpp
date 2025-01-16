// guard
#ifndef REGIONS_HPP_
#define REGIONS_HPP_

// library imports
#include <iostream>

class Region {
    public:
        std::string name;
        // for now, attitude as a singular representation
        // in future, improve logic to handle full attitude matrices
        int attitude;
        Region(std::string name="No Name Provided", int attitude=0);
};

// guard
#endif //REGIONS_HPP_