#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# define JACOBSTHAL 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531

# include <vector>
# include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &copy);
		void		fordJohnson(std::vector<unsigned int> &toSort, unsigned int depth);
		bool		runFordJohnson(char **strs, std::vector<unsigned int> &toSort, double &time);
		void		fordJohnson(std::deque<unsigned int> &toSort, unsigned int depth);
		bool		runFordJohnson(char **strs, std::deque<unsigned int> &toSort, double &time);
	private:
		void		_jacobsthalInsert(std::vector<unsigned int> &toSort, std::vector<unsigned int> &mainChain, unsigned int chunkSize, unsigned int chunkSizeX2) const;
		void		_jacobsthalInsert(std::deque<unsigned int> &toSort, std::deque<unsigned int> &mainChain, unsigned int chunkSize, unsigned int chunkSizeX2) const;
		static const unsigned int	_jacobsthal[];
		static const unsigned int	_jacobsthalLength;

};

#endif