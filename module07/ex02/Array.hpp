#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
    public:
        Array(); //empty array
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();
        Array &operator=(const Array &src);
        unsigned int    size() const;
        T   &operator[](long index) const;
    private:
        unsigned int    _n;
        T               *_arr;
};

#endif