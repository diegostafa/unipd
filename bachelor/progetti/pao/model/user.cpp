#include "user.h"

unsigned int user::field_length = 4;

user::user(const std::string& username, const std::string& password) : _username(username), _pw(password) {}

std::string user::get_username() const { return _username; }

std::string user::get_password() const { return _pw; }

void user::set_password(const std::string& password) {
  _pw = password;
}

bool user::operator==(const user &u) const { return _username == u._username; }
bool user::operator!=(const user &u) const { return _username != u._username; }
