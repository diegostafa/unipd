#ifndef DEEP_PTR_H
#define DEEP_PTR_H

template <class T> class deep_ptr {
private:
  T* _p;

public:
  deep_ptr(T* p = nullptr);
  deep_ptr(const deep_ptr& d);
  ~deep_ptr();

  void swap(deep_ptr<T>& x);

  bool operator==(const deep_ptr& d) const;
  bool operator!=(const deep_ptr& d) const;
  bool operator>(const deep_ptr& d) const;
  bool operator<(const deep_ptr& d) const;
  bool operator>=(const deep_ptr& d) const;
  bool operator<=(const deep_ptr& d) const;

  deep_ptr& operator=(const deep_ptr& d);
  operator bool() const;

  T& operator*();
  T* operator->();

  const T& operator*() const;
  const T* operator->() const;
};

template <class T>
deep_ptr<T>::deep_ptr(T* p) : _p(p) {}

template <class T>
deep_ptr<T>::deep_ptr(const deep_ptr& d) : _p(d._p ? d._p->clone() : nullptr) {}

template <class T> deep_ptr<T>::~deep_ptr() { delete _p; }

template <class T>
deep_ptr<T>& deep_ptr<T>::operator=(const deep_ptr& d) {
  if (this != &d) {
      delete _p;
      _p = d._p->clone();
    }
  return *this;
}

template <class T> T& deep_ptr<T>::operator*() { return *_p; }

template <class T> T* deep_ptr<T>::operator->() { return _p; }

template <class T> const T& deep_ptr<T>::operator*() const { return *_p; }

template <class T> const T* deep_ptr<T>::operator->() const { return _p; }

template <class T> void deep_ptr<T>::swap(deep_ptr<T>& d) {
  auto temp = _p;
  _p = d._p;
  d._p = temp;
}

template <class T> bool deep_ptr<T>::operator==(const deep_ptr& d) const { return *_p == *(d._p); }

template <class T> bool deep_ptr<T>::operator!=(const deep_ptr& d) const { return *_p != *(d._p); }

template <class T> bool deep_ptr<T>::operator>(const deep_ptr& d) const { return *_p >= *(d._p); }

template <class T> bool deep_ptr<T>::operator<(const deep_ptr& d) const { return *_p <= *(d._p); }

template <class T> bool deep_ptr<T>::operator>=(const deep_ptr& d) const { return *_p >= *(d._p); }

template <class T> bool deep_ptr<T>::operator<=(const deep_ptr& d) const { return *_p <= *(d._p); }

template <class T> deep_ptr<T>::operator bool() const { return _p ? true : false; }

#endif
