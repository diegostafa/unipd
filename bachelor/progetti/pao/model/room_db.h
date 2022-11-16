#ifndef ROOM_DB_H
#define ROOM_DB_H

#include "db.h"
#include "room.h"
#include <list>
#include <vector>

class room_db : public db<room*> {
private:
  std::list<room*> _rooms;
public:
  virtual bool add(room* r);
  virtual bool remove(room* r);
  virtual bool contains(room* r) const;
  virtual unsigned int size() const;
  virtual room* get(room* r);

  std::vector<room*> get_by_member(const std::string& member);
};
#endif // ROOM_DB_H
