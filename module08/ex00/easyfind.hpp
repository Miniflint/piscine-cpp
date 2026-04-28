#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
template<typename T>bool easyfind(T &a,int i){return std::find(a.begin(),a.end(),i)!=a.end();}
#endif