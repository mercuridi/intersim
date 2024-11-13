#include <iostream>
#include <vector>
#include <format>

using namespace std;
// expecting to split out this file to different cpp files for maintainability
// in the future. early dev, single file is easier to work with

class Event {
    public:
        // change in future to use a date representation instead of a year
        int year;
        string summary;
        Event(int year=900) {
            this->year = year;
            summary = std::format("This is a dummy event that occurred in the year {}", year);
        };
};

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
        Ledger() {};
        void recordEvent(Event event) {
            Ledger::events.push_back(event);
        };
        void printLedger() {
            for (int i = 0; i < events.size(); i++) {
                cout << Ledger::events[i].summary << "\n";
            }
        }
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

int main() {
    cout << __cplusplus;
    cout << "\nStarting program\n";
    Ledger ledger;
    cout << "Ledger created\n";
    Event event;
    cout << "Event created\n";
    ledger.recordEvent(event);
    cout << "Event recorded in ledger\n";
    ledger.printLedger();
    cout << "Ending program\n";
    return 0;
};