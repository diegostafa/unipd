#ifndef GENERIC_FILE_H
#define GENERIC_FILE_H

#include "file_message.h"

class generic_file : public file_message {
public:
  generic_file(const std::string& sender, std::time_t sent_t, const std::string& path, unsigned long int size, unsigned int reply_id = 0);
  virtual std::string to_string() const;
  virtual entry_type get_type() const;
  virtual generic_file *clone() const;
  virtual generic_file *copy_forward() const;
};

#endif
