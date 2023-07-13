#ifndef LOCATION_MESSAGE_H
#define LOCATION_MESSAGE_H

#include "message_entry.h"

class location_message : public message_entry {
private:
  float _lat;
  float _lon;

public:
  location_message(const std::string& sender, std::time_t sent_t, float lat = 0.0f, float lon = 0.0f, unsigned int reply_id = 0);
  float get_latitude() const;
  float get_longitude() const;
  void set_latitude(float lat);
  void set_longitude(float lon);

  virtual bool operator==(const entry &m) const;
  virtual bool operator!=(const entry &m) const;
  virtual std::string to_string() const;
  virtual entry_type get_type() const;
  virtual location_message *clone() const;
  location_message* copy_forward() const;
};

#endif
