#include "message_entry.h"

message_entry::message_entry(const std::string& sender, std::time_t sent_t, unsigned int reply_id) :
  entry(sent_t),
  _sender(sender),
  _reply_id(reply_id),
  _modified(false), _forwarded(false) {}

bool message_entry::is_modified() const { return _modified; }

bool message_entry::is_forwarded() const { return _forwarded; }

unsigned int message_entry::get_reply() const { return _reply_id; }

std::string message_entry::get_sender() const { return _sender; }

void message_entry::set_modified() { _modified = true; }

void message_entry::set_forwarded() { _forwarded = true; }

bool message_entry::is_message() const { return true; }
