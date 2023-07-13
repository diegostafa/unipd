#include "entry.h"
#include <ctime>

unsigned int entry::id_counter = 0;

entry::entry(std::time_t sent_t) :
    _id(++id_counter), _sent_t(sent_t) {}

unsigned int entry::get_id() const { return _id; }
std::time_t entry::get_time() const { return _sent_t; }

bool entry::operator==(const entry& m) const { return _id == m._id; }
bool entry::operator!=(const entry& m) const { return _id != m._id; }
bool entry::operator>(const entry& m) const { return _sent_t > m._sent_t; }
bool entry::operator<(const entry& m) const { return _sent_t < m._sent_t; }
bool entry::operator>=(const entry& m) const { return _sent_t >= m._sent_t; }
bool entry::operator<=(const entry& m) const { return _sent_t <= m._sent_t; }
