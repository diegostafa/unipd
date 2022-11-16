#ifndef USER_DB_H
#define USER_DB_H

#include "db.h"
#include "user.h"
#include "../utils/log_error.h"

#include <list>
#include <vector>

class user_db : public db<user*> {
private:
  std::list<user*> _users;
public:
  virtual bool add(user* u);
  virtual bool remove(user* u);
  virtual bool contains(user* u) const;
  virtual unsigned int size() const;
  virtual user* get(user* u);

  std::vector<user*> get_all_but(const std::string&  username);
  user *get_by_username(const std::string&  username);
  user *validate(const std::string&  username, const std::string&  password);
};

#endif
