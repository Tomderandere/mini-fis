#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    Coach::ceiling_displays.push_back(display);
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    Coach::seat_displays[seatId]=display;
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    for (size_t i = 0; i < Coach::ceiling_displays.size(); i++)
    {
        Coach::ceiling_displays[i].updateText(newText);
    }
    
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    if (Coach::seat_displays.find(seatId)!= Coach::seat_displays.end())
    {
     Coach::seat_displays[seatId]=newText;
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
