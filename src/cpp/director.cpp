#include <iostream>
#include <vector>

#include "../hpp/events.hpp"
#include "../hpp/director.hpp"

Director::Director(Calendar* calendarReference) {
    this->calendarReference = calendarReference;
}

void Director::calculateHistory(int stopYear) {

    while ((*calendarReference).currentYear < stopYear) {
        int d100 = std::rand() % 100;
        if (d100 < 80) {
            continue;
        }
        else {
            
        }
    }
}
