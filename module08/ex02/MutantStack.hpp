#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin(void);
		iterator	end(void);
		reverse_iterator	rbegin(void);
		reverse_iterator	rend(void);
		const_iterator	cbegin(void) const;
		const_iterator	cend(void) const;
		const_reverse_iterator	crbegin(void) const;
		const_reverse_iterator	crend(void) const;
		MutantStack();
		MutantStack(MutantStack const &src);
		MutantStack &operator=(MutantStack const &src);
		~MutantStack();
};

# include "MutantStack.tpp"

#endif
