#ifndef TEXT_MESSAGE_H
#define TEXT_MESSAGE_H

#include "message_entry.h"

class text_message : public message_entry {
private:
  std::string _content;
public:
  text_message(const std::string& sender, std::time_t sent_t, const std::string& content, unsigned int reply_id = 0);
  text_message(const message_entry &m);
  std::string get_content() const;
  void set_content(const std::string& s);
  virtual bool operator==(const entry &m) const;
  virtual bool operator!=(const entry &m) const;
  virtual text_message *clone() const;
  virtual entry_type get_type() const;
  virtual std::string to_string() const;
  virtual text_message* copy_forward() const;
};
#endif
