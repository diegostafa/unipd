#include "./model/user_db.h"

bool user_db::add(user* u){
  if(u->get_username().length() < user::field_length || u->get_password().length() < user::field_length)
    throw log_error("Input fields do not respect minimum length");
  else{
      if(!contains(u)){
          _users.push_back(u);
          return true;
        }
      return false;
    }
}

bool user_db::remove(user* u) {
  auto s = _users.size();
  _users.remove(u);
  return s != _users.size();
}

bool user_db::contains(user* u) const {
  for (auto i = _users.cbegin(); i != _users.cend(); i++)
    if (*u == **i)
      return true;
  return false;
}

unsigned int user_db::size() const { return _users.size(); }

user* user_db::get(user* u) {
  for (auto i = _users.begin(); i != _users.end(); i++)
    if (u == *i)
      return *i;
  return nullptr;
}

user *user_db::validate(const std::string&  username, const std::string&  password) {
  user *u = get_by_username(username);
  if(u)
    return u->get_password() == password ? u : nullptr;
  return nullptr;
}

user *user_db::get_by_username(const std::string&  username) {
  for (auto i = _users.begin(); i != _users.end(); i++)
    if ((*i)->get_username() == username)
      return *i;
  return nullptr;
}

std::vector<user*> user_db::get_all_but(const std::string& username) {
  std::vector<user*> v;
  for(auto i: _users)
    if(i->get_username() != username)
      v.push_back(i);
  return v;
}
