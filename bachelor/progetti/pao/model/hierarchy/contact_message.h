#ifndef CONTACT_MESSAGE_H
#define CONTACT_MESSAGE_H

#include "message_entry.h"

class contact_message : public message_entry {
private:
  std::string _number;
  std::string _name;

public:
  contact_message(const std::string& sender, std::time_t sent_t, const std::string& number, const std::string& name, unsigned int reply_id = 0);
  std::string get_number() const;
  std::string get_name() const;
  void set_number(const std::string& number);
  void set_name(const std::string& name);
  virtual bool operator==(const entry &m) const;
  virtual bool operator!=(const entry &m) const;
  virtual message_entry *clone() const;
  virtual message_entry *copy_forward() const;
  virtual entry_type get_type() const;
  virtual std::string to_string() const;
};  

#endif
