#include <iostream>
#include <vector>
using namespace std;
// expecting to split out this file to different cpp files for maintainability
// in the future. early dev, single file is easier to work with

class Calendar {
    public:
        // later, improve to add granularity to the calendar
        // years is good enough for early development
        int currentYear;
        void getCurrentDate() {
            cout << currentYear;
        };
};

class Director {
    public:
        void startWar(Region* sideA, Region* sideB) {

        };
};

class Ledger {
    public:
        vector<string> events;
        void recordEvent(string eventName) {
            
        };
}

class Region {
    public:
        string name;
        // for now, attitude as a singular representation
        // in future, improve logic to handle full attitude matrices
        int attitude;

};

int main() {

};