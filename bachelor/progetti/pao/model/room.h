#ifndef ROOM_H
#define ROOM_H

#include "hierarchy/entry.h"
#include "entry_creator.h"

#include "../utils/deep_ptr.h"
#include "../utils/vec.h"
#include "../utils/log_error.h"

#include <vector>

class room {
private:
  static unsigned int id_counter;
  const unsigned int _id;
  std::string _name;
  vec<deep_ptr<entry>> _entries;
  vec<std::string> _members;

public:
  room(const std::string& name, std::vector<std::string> members);

  std::string get_name() const;
  void set_name(const std::string& name);

  // members
  bool is_member(const std::string& username) const;
  void add_member(const std::string& member);
  void add_member(std::vector<std::string> members);
  void remove_member(const std::string& member);
  void remove_member(std::vector<std::string> members);
  std::vector<std::string> get_all_members() const;
  unsigned int num_members() const;

  // add & remove entries
  void write_text_message(const std::string& sender, const std::string& content, unsigned int reply_id = 0);
  void write_contact_message(const std::string& sender, const std::string& name, const std::string& number, unsigned int reply_id = 0);
  void write_location_message(const std::string& sender, float lat, float lon, unsigned int reply_id = 0);
  void write_image_file(const std::string& sender, const std::string& path, unsigned int reply_id = 0);
  void write_generic_file(const std::string& sender, const std::string& path, unsigned int reply_id = 0);

  void forward_message(const message_entry* e);
  void erase(const entry& e);
  void erase_by_id(unsigned int id);

  unsigned int num_entries() const;

  // filtering
  entry *get_by_id(unsigned int id);
  std::vector<entry *> get_by_date(time_t t);
  std::vector<entry *> get_by_date(time_t start, time_t end);
  std::vector<entry *> get_by_text(std::string text);
  std::vector<entry *> get_by_type(entry_type type);
  std::vector<entry *> get_all_entries();

  bool operator==(const room& r) const;
  bool operator!=(const room& r) const;
};

#endif
