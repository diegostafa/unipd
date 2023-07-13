#include "image_file.h"

image_file::image_file(const std::string& sender, std::time_t sent_t, const std::string& img_path, unsigned long int size, unsigned int width, unsigned int height, unsigned int reply_id)
    : file_message(sender, sent_t, img_path, size, reply_id), _width(width), _height(height) {}

unsigned int image_file::get_width() const { return _width; }
unsigned int image_file::get_height() const { return _height; }

std::string image_file::to_string() const {
    return file_message::to_string() + " - " + std::to_string(_width) + "x" +
        std::to_string(_height);
}
entry_type image_file::get_type() const { return entry_type::image_file; }
image_file* image_file::clone() const { return new image_file(*this); }
image_file* image_file::copy_forward() const {
  auto m = new image_file(message_entry::get_sender(), entry::get_time(), file_message::get_path(), file_message::get_size(), _width, _height, 0);
  m->set_forwarded();
  return  m;
}
