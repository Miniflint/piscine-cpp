#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <exception>
template<typename T> typename T::iterator easyfind(T &a,int i){
    typename T::iterator    it = std::find(a.begin(),a.end(),i);

    if (it == a.end())
        throw std::exception();
    return (it);
}
#endif