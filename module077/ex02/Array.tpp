#include "Array.hpp"
#include <exception>

template<typename T>
Array<T>::Array() : _n(0), _arr(new T[this->_n]) {}

template<typename T>
Array<T>::Array(unsigned int n) : _n(n), _arr(new T[this->_n]) {}

template<typename T>
Array<T>::Array(const Array<T> &src) : _n(src.size()), _arr(new T[this->_n])
{
    for (unsigned int i = 0; i < this->_n; ++i) {
        (*this)[i] = src[i];
    }
}

template<typename T>
Array<T>::~Array()
{
    delete [] this->_arr;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    delete [] this->_arr;
    this->_n = src.size();
    this->_arr = new T[this->_n];
    for (unsigned int i = 0; i < this->_n; ++i) {
        (*this)[i] = src[i];
    }
    return (*this);
}

template<typename T>
unsigned int    Array<T>::size() const
{
    return (this->_n);
}

template<typename T>
T   &Array<T>::operator[](long index) const
{
    if (index >= this->_n || index < 0)
        throw (std::exception());
    return (this->_arr[index]);
}
