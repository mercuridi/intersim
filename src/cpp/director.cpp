#include <iostream>
#include <vector>

#include "../hpp/events.hpp"

class Director {
    public:
        Event dummyEvent() {
            return Event();
        };
};