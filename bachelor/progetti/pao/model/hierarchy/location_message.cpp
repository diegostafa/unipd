#include "location_message.h"

location_message::location_message(const std::string& sender, std::time_t sent_t, float lat, float lon, unsigned int reply_id)
    : message_entry(sender, sent_t, reply_id), _lat(lat), _lon(lon) {}

float location_message::get_latitude() const { return _lat; }
float location_message::get_longitude() const { return _lon; }
void location_message::set_latitude(float lat) { _lat = lat; set_modified(); }
void location_message::set_longitude(float lon) { _lon = lon; set_modified(); }

bool location_message::operator==(const entry& m) const {
    return entry::operator==(m) &&_lat == static_cast<const location_message&>(m)._lat &&
        _lon == static_cast<const location_message&>(m)._lon;
}
bool location_message::operator!=(const entry& m) const {
    return !(entry::operator==(m) && _lat == static_cast<const location_message&>(m)._lat &&
        _lon == static_cast<const location_message&>(m)._lon);
}

std::string location_message::to_string() const {
    return "lat: " + std::to_string(_lat) + " - lon: " + std::to_string(_lon);
}
entry_type location_message::get_type() const { return entry_type::location_message; }

location_message* location_message::clone() const {
    return new location_message(*this);
}
location_message* location_message::copy_forward() const {
  auto m = new location_message(message_entry::get_sender(), entry::get_time(), _lat, _lon, 0);
  m->set_forwarded();
  return  m;
}
