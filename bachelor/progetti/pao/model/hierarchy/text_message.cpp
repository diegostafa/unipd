#include "text_message.h"


text_message::text_message(const std::string& sender, std::time_t sent_t, const std::string& content, unsigned int reply_id)
    : message_entry(sender, sent_t, reply_id), _content(content) {}

text_message::text_message(const message_entry& m)
    : message_entry(m.get_sender(), m.get_time()), _content(m.to_string()) {}

std::string text_message::get_content() const { return _content; }
void text_message::set_content(const std::string& s) { _content = s; set_modified(); }

bool text_message::operator==(const entry& m) const {
    return entry::operator==(m) && _content == static_cast<const text_message&>(m)._content;
}
bool text_message::operator!=(const entry& m) const {
    return !(entry::operator==(m) && _content == static_cast<const text_message&>(m)._content);
}

text_message* text_message::copy_forward() const {
  auto m = new text_message(message_entry::get_sender(), entry::get_time(), _content, 0);
  m->set_forwarded();
  return  m;
}

text_message* text_message::clone() const { return new text_message(*this); }
entry_type text_message::get_type() const { return entry_type::text_message; }
std::string text_message::to_string() const { return _content; };
