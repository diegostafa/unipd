#ifndef ENTRY_CREATOR_H
#define ENTRY_CREATOR_H

#include "hierarchy/text_message.h"
#include "hierarchy/location_message.h"
#include "hierarchy/contact_message.h"
#include "hierarchy/image_file.h"
#include "hierarchy/generic_file.h"

#include <chrono>
#include <fstream>

class entry_creator
{
private:
  std::time_t get_current_time() const;
  std::pair<unsigned int, unsigned int> get_image_dimension(const std::string& img_path) const;
  unsigned long int get_file_size(const std::string& path) const;

public:
  text_message* create_text_message(const std::string& sender, const std::string& content, unsigned int reply_id = 0) const;
  location_message* create_location_message(const std::string& sender, float lat, float lon, unsigned int reply_id = 0) const;
  contact_message* create_contact_message(const std::string& sender, const std::string& name, const std::string& number, unsigned int reply_id = 0) const;
  image_file* create_image_file(const std::string& sender, const std::string& path, unsigned int reply_id = 0) const;
  generic_file* create_generic_file(const std::string& sender, const std::string& path, unsigned int reply_id = 0) const;
};

#endif // ENTRY_CREATOR_H
