#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		iterator		begin(void);
		iterator		end(void);
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
		const_reverse_iterator	rbegin(void) const;
		const_reverse_iterator	rend(void) const;
		MutantStack();
		MutantStack(MutantStack const &src);
		MutantStack &operator=(MutantStack const &src);
		~MutantStack();
};

# include "MutantStack.tpp"

#endif
