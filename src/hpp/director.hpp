#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

#include "../hpp/calendar.hpp"
#include "../hpp/events.hpp"

class Director {
    public:
        // variables
        Calendar* calendarReference;

        // functions
        Director(Calendar calendarReference*);
        void calculateHistory(int stopYear);
};
#endif // DIRECTOR_HPP_
