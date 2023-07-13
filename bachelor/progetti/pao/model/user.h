#ifndef USER_H
#define USER_H

#include <string>

class user {
private:
  const std::string _username; // user ID
  std::string _pw;

public:
  static unsigned int field_length;

  user(const std::string& username, const std::string& password);

  std::string get_username() const;
  std::string get_password() const;
  void set_password(const std::string& password);

  bool operator==(const user& u) const;
  bool operator!=(const user& u) const;
};

#endif
