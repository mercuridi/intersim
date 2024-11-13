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
        Calendar(int startYear) {
            currentYear = startYear;
        }
        void printCurrentDate() {
            cout << currentYear;
        };
        void incrementYear() {
            currentYear++;
        }
};

class Director {
    public:
        Event dummyEvent() {
            return Event();
        };
};

class Ledger {
    public:
        vector<Event> events;
        void recordEvent(Event event) {
            Ledger::events.push_back(event);
        };
        void printLedger() {
            for (int i = events.size(); i > 0; i--) {
                cout << Ledger::events[i].summary << "\n";
            }
        }
};

class Event {
    public:
        // change in future to use a date representation instead of a year
        int year;
        string summary;
        Event(int year=900) {
            year = year;
            summary = "This is a dummy event that occurred in the year %i", year;
        };
};

class War: public Event {
    public:
        Region attacker;
        Region defender;
        Region winner;
        Region loser;
        War(Region attacker, Region defender) {
            this->attacker = attacker;
            this->defender = defender;
        };
};

class Region {
    public:
        string name;
        // for now, attitude as a singular representation
        // in future, improve logic to handle full attitude matrices
        int attitude;
        Region(string name="No Name Provided", int attitude=0) {
            this->name = name;
            this->attitude = attitude;
        }
};

int main() {

};