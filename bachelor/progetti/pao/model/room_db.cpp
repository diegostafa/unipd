#include "room_db.h"

bool room_db::add(room* r){
  if(!contains(r)){
      _rooms.push_back(r);
      return true;
    }
  return false;
}

bool room_db::remove(room* r) {
  auto s = _rooms.size();
  _rooms.remove(r);
  return s != _rooms.size();
}

bool room_db::contains(room* r) const {
  for (auto i = _rooms.cbegin(); i != _rooms.cend(); i++)
    if (*r == **i)
      return true;
  return false;
}

unsigned int room_db::size() const { return _rooms.size(); }

room* room_db::get(room* r) {
  for (auto i = _rooms.begin(); i != _rooms.end(); i++)
    if (*r == **i)
      return *i;
  return nullptr;
}

std::vector<room*> room_db::get_by_member(const std::string& member)
{
  std::vector<room*> aux;
  for(auto i = _rooms.begin(); i!= _rooms.end(); ++i)
    if((*i)->is_member(member))
      aux.push_back(*i);
  return aux;

}
