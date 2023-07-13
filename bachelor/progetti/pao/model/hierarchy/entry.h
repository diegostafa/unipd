#ifndef ENTRY_H
#define ENTRY_H

#include "entry_type.h"
#include <string>
#include <ctime>

class entry {
private:
  static unsigned int id_counter;
  const unsigned int _id;
  const std::time_t _sent_t;

public:
  entry(std::time_t sent_t);
  virtual ~entry() = default;

  unsigned int get_id() const;

  std::time_t get_time() const;

  virtual bool operator==(const entry& m) const;
  virtual bool operator!=(const entry& m) const;
  virtual bool operator>(const entry& m) const;
  virtual bool operator<(const entry& m) const;
  virtual bool operator>=(const entry& m) const;
  virtual bool operator<=(const entry& m) const;
  virtual bool is_message() const = 0;
  virtual entry_type get_type() const = 0;
  virtual std::string to_string() const = 0;
  virtual entry* clone() const = 0;
};

#endif
