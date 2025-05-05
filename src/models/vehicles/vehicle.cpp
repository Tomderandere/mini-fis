#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
coaches.push_back(coach);
reservations.emplace_back();
}

void Vehicle::addStop(std::string const& stop)
{
    route.push_back(stop);
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    int from = -1;
    int to = -1;

    for (size_t i = 0; i < route.size(); i++) {
        if (reservation.from == route[i]) {
            from = static_cast<int>(i);
        }
        if (reservation.to == route[i]) {
            to = static_cast<int>(i);
        }
    }

    // SitzID ("42") anlegen, falls noch nicht vorhanden:
    auto& seat_reservations = reservations[coachIndex][seatId];

    if (from != -1 && to != -1 && from < to) {
        // gültige Reservation hinzufügen
        seat_reservations.push_back(reservation);
    } else {
        std::cerr << "Ungültige Reservation: von "
                  << reservation.from << " nach " << reservation.to << std::endl;
        // Keine gültige Reservierung hinzufügen, aber der Sitz bleibt vorhanden
    }
}

void Vehicle::showAllDisplays() const
{
    for (const auto& coach : coaches) {
        coach.showAllDisplays();
    }
}

void Vehicle::showAllReservations() const
{
    for (size_t i = 0; i < coaches.size(); i++)  
    {
        std::cout << "Wagen " << i << " Reservierungen:" << std::endl;

        const auto& reservations_for_coach = reservations[i];

        for (const auto& seat_reservation : reservations_for_coach)
        {
            std::cout << "  Sitz: " << seat_reservation.first << " -> " << seat_reservation.second.size() << " Reservierungen" << std::endl;
            for (const auto& res : seat_reservation.second)
            {
                std::cout << "    - " << res.from << " nach " << res.to << std::endl;
            }
        }
    }
    
}

void Vehicle::setCurrentStop(size_t pos)
{
    
       next_stop=route[pos];
    
}


void Vehicle::arriveAtStop()
{
    int pos =-1;
    for (size_t i = 0; i < route.size(); i++)
    {
        if (route[i]==next_stop)
        {
            pos=i;
        }
        
    }
    
    if (pos >= route.size()) {
        return; // Keine gültige Station mehr
    }

    // Alle Coach-Displays auf den aktuellen Halt setzen
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays(next_stop);
    }

    // next_stop aktualisieren
    if (pos + 1 < route.size()) {
        next_stop = route[pos + 1];
    } else {
        next_stop = ""; // Kein nächster Halt mehr
    }
}

void Vehicle::departFromStop()
{
    int pos = 0;
    for (size_t i = 0; i < route.size(); i++) {
        if (route[i] == next_stop) {
            pos = i;
            break;  // Abbrechen, wenn die Position gefunden wurde
        }
    }

    // Alle Coach-Displays auf den aktuellen Halt setzen
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays("Nächster Halt: " + next_stop);
    }

  
}

void Vehicle::updateSeatDisplays()
{
    for (auto & coach : coaches)
    {
        // coach.updateSeatDisplay();
    }
    
}
