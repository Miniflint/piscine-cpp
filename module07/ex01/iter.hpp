#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename U, typename V>
void    iter(T *arr, const unsigned int len, U (f)(V))
{
    for (unsigned int i = 0; i < len; i++) {
        f(arr[i]);
    }
}

#endif