// guard
#ifndef REGIONS_HPP_
#define REGIONS_HPP_

// library imports
#include <iostream>
#include <climits>

class Region {
    public:
        Region(std::string name="No Name Provided", int attitude=INT_MAX);
        std::string getRegionName();
        int getAttitude();
        void setAttitude(int attitude);
        void nudgeAttitudeRandom(int warThres);
    private:
        std::string name;
        // for now, attitude as a singular representation
        // in future, improve logic to handle full attitude matrices
        int attitude;
};

// guard
#endif //REGIONS_HPP_