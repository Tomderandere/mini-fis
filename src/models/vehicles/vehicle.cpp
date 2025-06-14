#include "vehicle.h"
#include <iostream>
#include <algorithm>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
   Vehicle::coaches.push_back(coach);
   Vehicle::reservations.push_back({});
}

void Vehicle::addStop(std::string const& stop)
{
    Vehicle::route.push_back(stop);
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    auto& seat = Vehicle::reservations[coachIndex][seatId];
    auto from_it = std::find(route.begin(), route.end(), reservation.from);
    auto to_it = std::find(route.begin(), route.end(), reservation.to);
    if ( from_it != route.end()&& to_it!= route.end()&& from_it < to_it)
    {
    seat.push_back(reservation);
    }
    
    
}

void Vehicle::showAllDisplays() const
{
     // TODO
}

void Vehicle::showAllReservations() const
{
    // TODO
}

void Vehicle::setCurrentStop(size_t pos)
{
    Vehicle::next_stop=Vehicle::route[pos];
}

void Vehicle::arriveAtStop()
{
  for (size_t i = 0; i < Vehicle::coaches.size(); i++)
  {
   
    coaches[i].updateCeilingDisplays(next_stop);
   
    
  }
  for (size_t i = 0; i < route.size()-1; i++)
  {
    if (route[i]==next_stop)
    {
    Vehicle::setCurrentStop(i+1);
    }
  }
  
 
}

void Vehicle::departFromStop()
{
   for (size_t i = 0; i < Vehicle::coaches.size(); i++)
  {
   
    coaches[i].updateCeilingDisplays("Nächster Halt: "+next_stop);
   
    
  }
}

void Vehicle::updateSeatDisplays()
{
   //todo
    
}
