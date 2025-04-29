

#include "reservation_logic.h"
#include <algorithm>
#include <string>

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
auto entry_pos=std::find(stops.begin(), stops.end(), reservation.from);
auto exit_pos=std::find(stops.begin(), stops.end(), reservation.to);

if (entry_pos==stops.end() || exit_pos==stops.end())
{
   return;
}

if (entry_pos>exit_pos)
{
    return;
}

auto insert_pos = std::lower_bound(
    reservations.begin(), reservations.end(), reservation,
    [](const Reservation& a, const Reservation& b) {
        return a.from < b.from; // oder: komplexer, wenn nötig
    });
    
reservations.insert(insert_pos, reservation);
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{
    // TODO

    return Reservation();
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    // TODO

    return true;
}
