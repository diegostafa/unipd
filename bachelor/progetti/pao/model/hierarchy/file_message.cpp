#include "file_message.h"

file_message::file_message(const std::string& sender, std::time_t sent_t, const std::string& path, unsigned long int size, unsigned int reply_id)
    : message_entry(sender, sent_t, reply_id), _path(path), _size(size) {}

std::string file_message::get_path() const { return _path; }
unsigned long int file_message::get_size() const { return _size; }

bool file_message::operator==(const entry& m) const {
    return entry::operator==(m) && _path == static_cast<const file_message&>(m)._path;
}
bool file_message::operator!=(const entry& m) const {
    return !(entry::operator==(m) && _path != static_cast<const file_message&>(m)._path);
}
bool file_message::operator>(const message_entry& m) const {
    return _size > static_cast<const file_message&>(m)._size;
}
bool file_message::operator<(const message_entry& m) const {
    return _size < static_cast<const file_message&>(m)._size;
}
bool file_message::operator>=(const message_entry& m) const {
    return _size >= static_cast<const file_message&>(m)._size;
}
bool file_message::operator<=(const message_entry& m) const {
    return _size <= static_cast<const file_message&>(m)._size;
}

std::string file_message::to_string() const {
    return _path + " - " + std::to_string(_size/1024) + " KB";
}
