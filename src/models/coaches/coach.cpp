#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    ceiling_displays.push_back(display);
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    ;
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    // TODO
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    // TODO
}

void Coach::showCeilingDisplays() const
{
    // TODO
}

void Coach::showSeatDisplays() const
{
    // TODO
}

void Coach::showAllDisplays() const
{
    // TODO
}
