

#include "reservation_logic.h"
#include <algorithm>

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    // Überprüfen, ob die Reservierung gültig ist
    auto from_it = std::find(stops.begin(), stops.end(), reservation.from);
    auto to_it = std::find(stops.begin(), stops.end(), reservation.to);

    if (from_it == stops.end() || to_it == stops.end() || from_it >= to_it) {
        return; // Ungültige Reservierung, nicht hinzufügen
    }

    // Füge die Reservierung in die Liste ein
    reservations.push_back(reservation);

    // Sortiere die Reservierungen basierend auf den Haltestellen
    std::sort(reservations.begin(), reservations.end(), [&stops](Reservation const& a, Reservation const& b) {
        return std::find(stops.begin(), stops.end(), a.from) < std::find(stops.begin(), stops.end(), b.from);
    });
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{

for (size_t i = 0; i < reservations.size(); i++)
{
     if (reservations[i].to==next_stop)
   {
  return reservations[i];
   }
   if (reservations[i].from==next_stop)
   {
  return reservations[i];
   }
   
    
}
    return Reservation();
    
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    auto from_it = std::find(stops.begin(), stops.end(), reservation.from);
    auto to_it = std::find(stops.begin(), stops.end(), reservation.to);
    return from_it<to_it && from_it!=stops.end() && to_it != stops.end();
}
