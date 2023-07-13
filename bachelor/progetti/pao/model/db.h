#ifndef DB_H
#define DB_H

template <class T>
class db
{
public:
  virtual bool add(T item) = 0;
  virtual bool remove(T item) = 0;
  virtual bool contains(T item) const = 0;
  virtual T get(T item) = 0;
  virtual unsigned int size() const = 0;
  virtual ~db() = default;
};


#endif // DB_H
