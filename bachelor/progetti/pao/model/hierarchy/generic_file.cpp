#include "generic_file.h"

generic_file::generic_file(const std::string& sender, std::time_t sent_t, const std::string& path, unsigned long int size, unsigned int reply_id)
    : file_message(sender, sent_t, path, size, reply_id) {}

std::string generic_file::to_string() const {
    return file_message::to_string() + " - generic file";
}
entry_type generic_file::get_type() const { return entry_type::generic_file; }
generic_file* generic_file::clone() const { return new generic_file(*this); }
generic_file* generic_file::copy_forward() const {
  auto m = new generic_file(message_entry::get_sender(), entry::get_time(), file_message::get_path(), file_message::get_size(), 0);
  m->set_forwarded();
  return  m;
}
