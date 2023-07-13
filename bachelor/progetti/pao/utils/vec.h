#ifndef VEC_H
#define VEC_H

template <class T> class vec {

private:
    T* _elements;
    unsigned int _size;
    unsigned int _space;

public:
    class iterator {
        friend class vec<T>;

    private:
        T* _curr;

    public:
        iterator(T* p);
        iterator(const iterator& cit);
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        T& operator*() const;
        T* operator&() const;
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
    };

    class const_iterator {
        friend class vec<T>;

    private:
        const T* _curr;

    public:
        const_iterator(T* p);
        const_iterator(const const_iterator& cit);
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const T& operator*() const;
        const T* operator&() const;
        bool operator==(const const_iterator& cit) const;
        bool operator!=(const const_iterator& cit) const;
    };

    // constructors
    vec(unsigned int capacity = 0);
    vec(const vec& v);
    ~vec();
    vec& operator=(const vec& v);

    // iterator interface
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    // vector state
    bool is_empty() const;
    unsigned int size() const;
    unsigned int capacity() const;
    int index_of(const T& element) const;
    bool contains(const T& element) const;

    // modifiers
    void join(const vec& v);
    void push_back(const T& element);
    void pop_back();
    void clear();

    void remove(const T& element);
    void remove_at(unsigned int index);

    void reserve(unsigned int dim);
    void shrink_to_fit();

    // accessors
    T& operator[](unsigned int index);
    T& front();
    T& back();

    // const accessors
    const T& operator[](unsigned int index) const;
    const T& front() const;
    const T& back() const;
};

/// ITERATORS ///

template <class T> vec<T>::iterator::iterator(T* p) : _curr(p) {}

template <class T>
vec<T>::iterator::iterator(const iterator& cit) : _curr(cit._curr) {}

template <class T> typename vec<T>::iterator& vec<T>::iterator::operator++() {
    _curr++;
    return *this;
}

template <class T> typename vec<T>::iterator vec<T>::iterator::operator++(int) {
    auto aux = *this;
    _curr++;
    return aux;
}

template <class T> typename vec<T>::iterator& vec<T>::iterator::operator--() {
    _curr--;
    return *this;
}

template <class T> typename vec<T>::iterator vec<T>::iterator::operator--(int) {
    auto aux = *this;
    _curr--;
    return aux;
}

template <class T> T& vec<T>::iterator::operator*() const { return *_curr; }

template <class T> T* vec<T>::iterator::operator&() const { return &_curr; }

template <class T> bool vec<T>::iterator::operator==(const iterator& it) const {
    return _curr == it._curr;
}

template <class T> bool vec<T>::iterator::operator!=(const iterator& it) const {
    return _curr != it._curr;
}



template <class T> vec<T>::const_iterator::const_iterator(T* p) : _curr(p) {}

template <class T>
vec<T>::const_iterator::const_iterator(const const_iterator& cit)
    : _curr(cit._curr) {}

template <class T>
typename vec<T>::const_iterator& vec<T>::const_iterator::operator++() {
    _curr++;
    return *this;
}

template <class T>
typename vec<T>::const_iterator vec<T>::const_iterator::operator++(int) {
    auto aux = *this;
    _curr++;
    return aux;
}

template <class T>
typename vec<T>::const_iterator& vec<T>::const_iterator::operator--() {
    _curr--;
    return *this;
}

template <class T>
typename vec<T>::const_iterator vec<T>::const_iterator::operator--(int) {
    auto aux = *this;
    _curr--;
    return aux;
}

template <class T> const T& vec<T>::const_iterator::operator*() const {
    return *_curr;
}

template <class T> const T* vec<T>::const_iterator::operator&() const {
    return &_curr;
}

template <class T>
bool vec<T>::const_iterator::operator==(const const_iterator& cit) const {
    return _curr == cit._curr;
}

template <class T>
bool vec<T>::const_iterator::operator!=(const const_iterator& cit) const {
    return _curr != cit._curr;
}

/// VECTOR ///

template <class T>
vec<T>::vec(unsigned int capacity)
    : _elements(capacity ? new T[capacity] : nullptr), _size(capacity),
    _space(capacity) {}

template <class T>
vec<T>::vec(const vec& v)
    : _elements(v._size == 0 ? nullptr : new T[v._size]), _size(v._size),
    _space(v._space) {
    for (unsigned int i = 0; i < _size; ++i)
        _elements[i] = v._elements[i];
}

template <class T> vec<T>& vec<T>::operator=(const vec<T>& v) {
    if (this != &v) {
        delete[] _elements;
        _size = v._size;
        _space = v._space;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _elements[i] = v._elements[i];
    }
    return *this;
}

template <class T> vec<T>::~vec() {
    delete[] _elements;
}

template <class T> typename vec<T>::iterator vec<T>::begin() {
    return _elements;
}

template <class T> typename vec<T>::iterator vec<T>::end() {
    return _elements + _size;
}

template <class T> typename vec<T>::const_iterator vec<T>::begin() const {
    return _elements;
}

template <class T> typename vec<T>::const_iterator vec<T>::end() const {
    return _elements + _size;
}

template <class T> typename vec<T>::const_iterator vec<T>::cbegin() const {
    return _elements;
}

template <class T> typename vec<T>::const_iterator vec<T>::cend() const {
    return _elements + _size;
}



template <class T> unsigned int vec<T>::capacity() const { return _space; }

template <class T> unsigned int vec<T>::size() const { return _size; }

template <class T> bool vec<T>::is_empty() const { return _size == 0; }



template <class T> void vec<T>::reserve(unsigned int dim)
{
    if (dim > _space)
    {
        T* aux = new T[dim];
        for (unsigned int i = 0; i < _size; i++)
            aux[i] = _elements[i];

        _space = dim;
        delete[] _elements;
        _elements = aux;
    }
}

template <class T> void vec<T>::push_back(const T& element) {

    if (_space == 0)
        reserve(8);
    else if (_size == _space)
        reserve(_space * 2);
    _elements[_size++] = element;
}

template <class T> void vec<T>::shrink_to_fit() {
    if (_size != _space) {
        T* aux = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            aux[i] = _elements[i];
        delete[] _elements;
        _elements = aux;
        _space = _size;
    }
}

template <class T> void vec<T>::pop_back() {
    if (_size > 0)
        _size--;
}

template <class T> void vec<T>::join(const vec& v) {
    if (v._size != 0) {
        reserve(v._size);
        for (unsigned int i = _size; i < v._size; i++)
            _elements[i] = v[i];
    }
}

template <class T> void vec<T>::clear() { _size = 0; }

template <class T> void vec<T>::remove(const T& element) {
    unsigned int count = 0;
    T* aux = new T[_space];

    for (unsigned int i = 0; i < _size; i++) {
        if (_elements[i] == element)
            count++;
        else
            aux[i - count] = _elements[i];
    }

    delete[] _elements;
    _size -= count;
    _elements = aux;
}

template <class T> void vec<T>::remove_at(unsigned int index) {
    if (index < _size) {
        T* aux = new T[_space];
        for (unsigned int i = 0; i < _size - 1; i++) {
            if (i < index)
                aux[i] = _elements[i];
            else if (i > index)
                aux[i] = _elements[i + 1];
        }
        delete[] _elements;
        _size--;
        _elements = aux;
    }
}



template <class T> T& vec<T>::operator[](unsigned int i) {
    return _elements[i];
}

template <class T> T& vec<T>::front() { return _elements[0]; }

template <class T> T& vec<T>::back() { return _elements[_size - 1]; }



template <class T> const T& vec<T>::operator[](unsigned int i) const {
    return _elements[i];
}

template <class T> const T& vec<T>::front() const { return _elements[0]; }

template <class T> const T& vec<T>::back() const {
    return _elements[_size - 1];
}



template <class T> int vec<T>::index_of(const T& element) const {
    for (unsigned int i = 0; i < _size; i++)
        if (_elements[i] == element)
            return i;
    return -1;
}

template <class T> bool vec<T>::contains(const T& element) const {
    return index_of(element) != -1;
}

#endif
