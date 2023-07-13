#include "room.h"

unsigned int room::id_counter = 0;


room::room(const std::string& name, std::vector<std::string> members) : _id(++id_counter), _name(name) {
  for (auto i = members.begin(); i != members.end(); ++i)
    _members.push_back(*i);
}

std::string room::get_name() const { return _name; }

void room::set_name(const std::string& chat_name) { _name = chat_name; }

std::vector<std::string> room::get_all_members() const {
  std::vector<std::string> aux;
  for (auto i = _members.cbegin(); i != _members.cend(); ++i)
    aux.push_back(*i);
  return aux;
}

void room::add_member(const std::string& username) {
  if (!_members.contains(username))
    _members.push_back(username);
}

void room::remove_member(const std::string& username) {
  _members.remove(username);
}

void room::add_member(std::vector<std::string> members) {
  for (auto i = members.begin(); i != members.end(); ++i)
    add_member(*i);
}

void room::remove_member(std::vector<std::string>  members) {
  for (auto i = members.begin(); i != members.end(); ++i)
    remove_member(*i);
}

bool room::is_member(const std::string& username) const {
  return _members.contains(username);
}

unsigned int room::num_members() const { return _members.size(); }

// add & remove entries
void room::write_text_message(const std::string& sender, const std::string& content, unsigned int reply_id) {
  entry_creator creator;
  _entries.push_back(creator.create_text_message(sender, content, reply_id));
}
void room::write_contact_message(const std::string& sender, const std::string& name, const std::string& number, unsigned int reply_id) {
  entry_creator creator;
  _entries.push_back(creator.create_contact_message(sender, name, number, reply_id));
}
void room::write_location_message(const std::string& sender, float lat, float lon, unsigned int reply_id) {
  if(lat >= -90.0f  && lat <= 90.0f && lon >= -180.0f  && lon <= 180.0f){
      entry_creator creator;
      _entries.push_back(creator.create_location_message(sender, lat, lon, reply_id));
    }
}
void room::write_image_file(const std::string& sender, const std::string& path, unsigned int reply_id) {
  entry_creator creator;
  _entries.push_back(creator.create_image_file(sender, path, reply_id));
}
void room::write_generic_file(const std::string& sender, const std::string& path, unsigned int reply_id) {
  entry_creator creator;
  _entries.push_back(creator.create_generic_file(sender, path, reply_id));
}

void room::forward_message(const message_entry* m) {
  _entries.push_back(m->copy_forward());
}


void room::erase(const entry& e) {
  _entries.remove(e.clone());
}


unsigned int room::num_entries() const { return _entries.size(); }

entry* room::get_by_id(unsigned int id) {
  for (auto i = _entries.begin(); i != _entries.end(); i++)
    if ((*i)->get_id() == id)
      return &**i;
  return nullptr;
}
std::vector<entry*> room::get_by_date(time_t t) {
  std::vector<entry*> match;
  for (auto i = _entries.begin(); i != _entries.end(); i++) {
      if ((*i)->get_time() == t)
        match.push_back(&**i);
    }
  return match;
}
std::vector<entry*> room::get_by_date(time_t start, time_t end) {
  std::vector<entry*> match;
  for (auto i = _entries.begin(); i != _entries.end(); i++) {
      if ((*i)->get_time() >= start && (*i)->get_time() <= end)
        match.push_back(&**i);
    }
  return match;
}
std::vector<entry*> room::get_by_type(entry_type type) {
  std::vector<entry*> match;
  for (auto i = _entries.begin(); i != _entries.end(); i++) {
      if ((*i)->get_type() == type)
        match.push_back(&**i);
    }
  return match;
}
std::vector<entry*> room::get_by_text(std::string text) {
  std::vector<entry*> match;
  for (auto i = _entries.begin(); i != _entries.end(); i++) {
      if ((*i)->to_string().find(text) != std::string::npos)
        match.push_back(&**i);
    }
  return match;
}
std::vector<entry*> room::get_all_entries() {
  std::vector<entry*> all;
  for (auto i = _entries.begin(); i != _entries.end(); i++) {
      all.push_back(&**i);
    }
  return all;
}

bool room::operator==(const room& r) const { return _id == r._id; }

bool room::operator!=(const room& r) const { return _id != r._id; }
