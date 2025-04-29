

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
if (reservations.empty()|| next_stop.empty()||stops.empty())
{
    return Reservation();
}
auto next_it = std::find(stops.begin(), stops.end(), next_stop);
if (next_it==stops.end()){
    return Reservation();
}
int next_index = std::distance(stops.begin(),next_it);
for( auto const& res : reservations){
    auto it_to = std::find(stops.begin(), stops.end(), res.to);
    if (it_to == stops.end()){
        continue;
    }
    int to_index = std::distance(stops.begin(), it_to);

    if (res.to == next_stop || to_index > next_index){
        return res;
    }
}
    return Reservation();
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    // TODO

    return true;
}
