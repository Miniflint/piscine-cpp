#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN	&operator=(const RPN &copy);
		bool	rpn(std::string expression);
	private:
		std::stack<int>	_stack;
		bool	_rpn_error();
};

#endif