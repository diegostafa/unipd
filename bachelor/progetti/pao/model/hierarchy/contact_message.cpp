#include "contact_message.h"

contact_message::contact_message(const std::string& sender, std::time_t sent_t, const std::string& name, const std::string& number, unsigned int reply_id)
    : message_entry(sender, sent_t, reply_id), _number(number), _name(name) {}

std::string contact_message::get_number() const { return _number; }
std::string contact_message::get_name() const { return _name; }

void contact_message::set_number(const std::string& number) { _number = number; set_modified(); }
void contact_message::set_name(const std::string& name) { _name = name; set_modified(); }


bool contact_message::operator==(const entry& m) const {
    return _number == static_cast<const contact_message&>(m)._number;
}
bool contact_message::operator!=(const entry& m) const {
    return !(_number == static_cast<const contact_message&>(m)._number);
}

message_entry* contact_message::clone() const { return new contact_message(*this); }
message_entry* contact_message::copy_forward() const {
  auto m = new contact_message(message_entry::get_sender(), entry::get_time(), _name, _number, 0);
  m->set_forwarded();
  return  m;
}
entry_type contact_message::get_type() const { return entry_type::contact_message; }
std::string contact_message::to_string() const { return _name + " @ " + _number; }
