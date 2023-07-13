#ifndef FILE_MESSAGE_H
#define FILE_MESSAGE_H

#include "message_entry.h"


class file_message : public message_entry {
private:
  const std::string _path;
  unsigned long int _size;

public:
  file_message(const std::string& sender, std::time_t sent_t, const std::string& path, unsigned long int size, unsigned int reply_id = 0);
  std::string get_path() const;
  unsigned long int get_size() const;
  virtual bool operator==(const entry &m) const;
  virtual bool operator!=(const entry &m) const;
  virtual bool operator>(const message_entry &m) const;
  virtual bool operator<(const message_entry &m) const;
  virtual bool operator>=(const message_entry &m) const;
  virtual bool operator<=(const message_entry &m) const;

  virtual std::string to_string() const;
};

#endif
