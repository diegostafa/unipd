#ifndef IMAGE_FILE_H
#define IMAGE_FILE_H

#include "file_message.h"

class image_file : public file_message {
private:
  const unsigned int _width;
  const unsigned int _height;

public:
  image_file(const std::string& sender, std::time_t sent_t, const std::string& img_path, unsigned long int size, unsigned int x, unsigned int y, unsigned int reply_id = 0);

  unsigned int get_width() const;
  unsigned int get_height() const;

  virtual std::string to_string() const;
  virtual entry_type get_type() const;
  virtual image_file *clone() const;
  virtual image_file *copy_forward() const;
};


#endif
