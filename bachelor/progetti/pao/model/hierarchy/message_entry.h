#ifndef MESSAGE_ENTRY_H
#define MESSAGE_ENTRY_H

#include "entry.h"

class message_entry : public entry {
private:
  const std::string _sender;
  unsigned int _reply_id;
  bool _modified;
  bool _forwarded;

protected:
  void set_modified();
  void set_forwarded();
public:
  message_entry(const std::string& sender, std::time_t sent_t, unsigned int reply_id = 0);
  bool is_modified() const;
  bool is_forwarded() const;
  std::string get_sender() const;
  unsigned int get_reply() const;
  virtual bool is_message() const;
  virtual message_entry* copy_forward() const = 0;
};

#endif
