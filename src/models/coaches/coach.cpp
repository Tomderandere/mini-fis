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
    seat_displays[seatId]= display;
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
   for (size_t i = 0; i < ceiling_displays.size(); i++)
   {
    ceiling_displays[i].updateText(newText);
   }
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
   auto it = seat_displays.find(seatId);
   if (it != seat_displays.end()) {
    it->second.updateText(newText);
}
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
